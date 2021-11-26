#include "Map2D.h"

Map2D::Map2D()
	: width_(0), height_(0)
{
}

Map2D::Map2D(TileType const* tiles, const std::size_t width, const std::size_t height)
	: width_(width), height_(height)
{
	tiles_.reserve(width_ * height_);
	for (std::size_t j = 0; j < height_; ++j)
	{
		for (std::size_t i = 0; i < width_; ++i)
		{
			const std::size_t current_index = i + j * width_;
			const TileType tile_type = tiles[current_index];
			tiles_.emplace_back(tile_type);
		}
	}
}

Tile& Map2D::operator[](const std::size_t index)
{
	return tiles_[index];
}

Tile& Map2D::at(const std::size_t i, const std::size_t j)
{
	return tiles_[i + j * width_];
}

const Tile& Map2D::at(const std::size_t i, const std::size_t j) const
{
	return tiles_[i + j * width_];
}
