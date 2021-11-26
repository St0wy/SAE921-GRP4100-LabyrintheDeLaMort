#include <SFML/Graphics.hpp>
#include <chrono>

#include "Hero.h"
#include "Consts.h"
#include "TileMap.h"
#include "Map2D.h"

//std::vector<std::unique_ptr<Tile>> generate_map(const sf::Texture& world_tilemap);

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

	// Create the tilemap
	Map2D map(MAP_LAYOUT, MAP_WIDTH, MAP_HEIGHT);
	TileMap tilemap;
	tilemap.load(TILEMAP_PATH, SPRITE_SIZE, map, MAP_WIDTH, MAP_HEIGHT);

	// Create the vector of entities
	std::vector<std::unique_ptr<Entity>> entities;

	// Create the hero
	entities.emplace_back(std::make_unique<Hero>(gen));
	auto hero = dynamic_cast<Hero*>(entities[0].get());
	hero->set_texture(char_spritesheet, sf::IntRect(sf::Vector2i(0, 80), sf::Vector2i(SPRITE_SIZE)));

	//for (auto& entity : entities)
	//{
	//	if (auto wall = dynamic_cast<Wall*>(entity.get()))
	//	{
	//		hero->add_wall(wall);
	//	}
	//}

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time delta_time = clock.restart();
		sf::Event event{};

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update all the entities
		if (window.hasFocus())
		{
			for (auto& entity : entities)
			{
				entity->update(delta_time);
			}
		}

		// Rendering
		window.clear(sf::Color::Black);

		// Render all the entities
		window.draw(tilemap);
		for (auto& entity : entities)
		{
			window.draw(*entity);
		}

		window.display();
	}
}

//std::vector<std::unique_ptr<Tile>> generate_map(const sf::Texture& world_tilemap)
//{
//	std::vector<std::unique_ptr<Tile>> entities;
//	entities.emplace_back(std::make_unique<Wall>());
//	const auto wall = dynamic_cast<Wall*>(entities[0].get());
//	wall->setPosition(20, 20);
//	wall->set_texture(world_tilemap, sf::IntRect(sf::Vector2i(32, 96), SPRITE_SIZE));
//
//	return entities;
//}