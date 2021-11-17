#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "vec_utils.h"

constexpr int WINDOW_WIDTH = 900;
constexpr int WINDOW_HEIGHT = 600;
constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";
constexpr float SPEED = 300.0f;

void compute_move(sf::Transformable& transformable, sf::Time delta_time);

int main()
{
	std::default_random_engine gen;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAMERATE);

	Hero hero(gen);
	hero.set_texture("data/hero.png");

	sf::Vector2f window_center(window.getSize());
	window_center /= 2.0f;
	hero.setPosition(window_center);

	sf::Clock clock;
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis
		// la pr�c�dente it�ration
		sf::Event event{};

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// �v�nement "fermeture demand�e" : on ferme la fen�tre
			case sf::Event::Closed:
				window.close();
			default:
				break;
			}
		}

		compute_move(hero, clock.restart());

		// Graphical Region
		window.clear(sf::Color::Black);

		window.draw(hero);

		window.display();
	}
}

void compute_move(sf::Transformable& transformable, const sf::Time delta_time)
{
	sf::Vector2f move;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move += sf::Vector2f(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move += sf::Vector2f(0, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move += sf::Vector2f(-1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move += sf::Vector2f(1, 0);
	}

	normalize(move);

	move *= SPEED * delta_time.asSeconds();

	transformable.move(move);
}