#pragma once

#include <SFML/Graphics.hpp>

#include "Map2D.h"

// Inspired by : https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
class TileMap final
	: public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray vertices_;
	sf::Texture tileset_;
public:
	bool load(const std::string& tileset_path, sf::Vector2u tile_size, const Map2D& map, std::size_t width, std::size_t height);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};