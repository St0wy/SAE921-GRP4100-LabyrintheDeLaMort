#include <SFML/Graphics.hpp>
#include <chrono>
#include "Hero.h"
#include "VecUtils.h"
#include "FrameAnimation.h"

constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";
constexpr float SPEED = 100.0f;
const sf::Vector2i SPRITE_SIZE(16, 16);
constexpr int WINDOW_SCALE = 5;
constexpr int CAM_SIZE_X = 16 * 16;
constexpr int CAM_SIZE_Y = 16 * 9;
constexpr int WINDOW_WIDTH = CAM_SIZE_X * WINDOW_SCALE;
constexpr int WINDOW_HEIGHT = CAM_SIZE_Y * WINDOW_SCALE;

void compute_move(Hero& hero, sf::Time delta_time);

int main()
{
	const auto seed = static_cast<uint32_t>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::default_random_engine gen(seed);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAMERATE);

	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(CAM_SIZE_X, CAM_SIZE_Y));

	window.setView(view);

	sf::Texture char_spritesheet;
	char_spritesheet.loadFromFile("./data/sprites/char_spritesheet.png");
	char_spritesheet.setSmooth(false);

	Hero hero(gen);
	hero.set_texture(char_spritesheet, sf::IntRect(sf::Vector2i(0, 80), SPRITE_SIZE));

	FrameAnimation idle(hero.get_sprite(), 0.6f), walk(hero.get_sprite(), 0.6f);

	for (int i = 0; i < 6; ++i)
	{
		idle.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80), SPRITE_SIZE));
		walk.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80 + SPRITE_SIZE.x), SPRITE_SIZE));
	}

	/*thor::Animator<sf::Sprite, std::string> animator;
	animator.addAnimation("idle", idle, sf::seconds(1.0f));
	animator.addAnimation("walk", walk, sf::seconds(1.0f));
	animator.playAnimation("idle");*/

	sf::Clock clock;
	while (window.isOpen())
	{
		auto delta_time = clock.restart();
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis
		// la précédente itération
		sf::Event event{};

		while (window.pollEvent(event))
		{
			switch (event.type)  // NOLINT(clang-diagnostic-switch-enum)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		compute_move(hero, delta_time);

		switch (hero.get_state())
		{
		case HeroState::Idle:
			idle.update(delta_time.asSeconds());
			break;
		case HeroState::Walk:
			walk.update(delta_time.asSeconds());
			break;
		}

		// Graphical Region
		window.clear(sf::Color::Black);

		window.draw(hero);
		window.draw(hero);

		window.display();
	}
}

void compute_move(Hero& hero, const sf::Time delta_time)
{
	sf::Vector2f move;
	hero.set_state(HeroState::Idle);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move += sf::Vector2f(0, -1);
		hero.set_state(HeroState::Walk);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move += sf::Vector2f(0, 1);
		hero.set_state(HeroState::Walk);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move += sf::Vector2f(-1, 0);
		hero.set_state(HeroState::Walk);
		hero.setScale(-1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move += sf::Vector2f(1, 0);
		hero.set_state(HeroState::Walk);
		hero.setScale(1, 1);
	}

	normalize(move);

	move *= SPEED * delta_time.asSeconds();

	hero.move(move);
}