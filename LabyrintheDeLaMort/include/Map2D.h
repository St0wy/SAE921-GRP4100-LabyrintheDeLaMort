#pragma once
#include <vector>

#include "Tile.h"

class Map2D
{
private:
	std::size_t width_;
	std::size_t height_;
	std::vector<Tile> tiles_;
public:
	Map2D();
	Map2D(TileType const* tiles, std::size_t width, std::size_t height);

	Tile& at(std::size_t i, std::size_t j);
	[[nodiscard]] const Tile& at(std::size_t i, std::size_t j) const;
};