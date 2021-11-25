#pragma once
#include "SFML/Graphics.hpp"

#include "TileType.h"

class Tile
{
private:
	TileType tile_type_;
public:
	Tile();
	explicit Tile(TileType tile_type);

	[[nodiscard]] TileType get_tile_type() const;

	[[nodiscard]] sf::Vector2i get_tile_pos() const;
};