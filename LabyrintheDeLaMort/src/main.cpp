#include <SFML/Graphics.hpp>
#include <chrono>

#include "Hero.h"
#include "Consts.h"

int main()
{
	// Create random engine
	const auto seed = static_cast<uint32_t>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::default_random_engine gen(seed);

	// Create render window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAMERATE);

	// Create view (camera) of the scene and set it to the window
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(CAM_SIZE_X, CAM_SIZE_Y));
	window.setView(view);

	// Load the spritesheet
	sf::Texture char_spritesheet;
	char_spritesheet.loadFromFile("./data/sprites/char_spritesheet.png");

	// Create the vector of entities
	std::vector<std::unique_ptr<Entity>> entities;
	entities.emplace_back(std::make_unique<Hero>(gen));
	entities[0]->set_texture(char_spritesheet, sf::IntRect(sf::Vector2i(0, 80), SPRITE_SIZE));

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time delta_time = clock.restart();
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

		// Update all the entities
		for (auto& entity : entities)
		{
			entity->update(delta_time);
		}

		// Rendering
		window.clear(sf::Color::Black);

		// Render all the entities
		for (auto& entity : entities)
		{
			window.draw(*entity);
		}
		window.display();
	}
}