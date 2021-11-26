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

	
	/**
	 * \brief Gets the position of the tile on the tile map. Not in pixels but in texture coordinate.
	 * (One sprite on the tile map = increment of one)
	 * \return A vector representing the position of the tile.
	 */
	[[nodiscard]] sf::Vector2i get_tile_pos() const;
};