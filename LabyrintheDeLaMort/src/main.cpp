#include <SFML/Graphics.hpp>
#include <chrono>

#include "Hero.h"
#include "Consts.h"

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

	std::vector<std::unique_ptr<Entity>> entities;
	entities.emplace_back(std::make_unique<Hero>(gen));
	entities[0]->set_texture(char_spritesheet, sf::IntRect(sf::Vector2i(0, 80), SPRITE_SIZE));

	sf::Clock clock;
	while (window.isOpen())
	{
		auto delta_time = clock.restart();
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

		for (auto& entity : entities)
		{
			entity->update(delta_time);
		}

		// Graphical Region
		window.clear(sf::Color::Black);

		for (auto& entity : entities)
		{
			window.draw(*entity);
		}

		window.display();
	}
}