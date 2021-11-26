#include "Tile.h"

Tile::Tile()
	:Tile(TileType::Empty)
{
}

Tile::Tile(const TileType tile_type)
	: tile_type_(tile_type)
{
}

TileType Tile::get_tile_type() const
{
	return tile_type_;
}

sf::Vector2i Tile::get_tile_pos() const
{
	switch (tile_type_)
	{

	case TileType::DirtOne:
		return { 5, 3 };
	case TileType::DirtTwo:
		return { 5, 2 };
	case TileType::BSquare:
		return { 3, 1 };
	case TileType::HSquareE:
		return { 0, 2 };
	case TileType::HSquareW:
		return { 1, 2 };
	case TileType::SSquare:
		return { 2, 1 };
	case TileType::ThreeSSquare:
		return { 2, 2 };
	case TileType::HalfSSquare:
		return { 3, 2 };
	case TileType::SSquareTransiN:
		return { 4, 2 };
	case TileType::SSquareTransiS:
		return { 4, 3 };
	case TileType::SSquareTransiE:
		return { 3, 3 };
	case TileType::SSquareTransiW:
		return { 2, 3 };
	case TileType::LightSSquare1:
		return { 6, 3 };
	case TileType::LightSSquare13:
		return { 6, 2 };
	case TileType::LightSSquare123:
		return { 6, 1 };
	case TileType::LightSSquare12:
		return { 7, 1 };
	case TileType::LightSSquare124:
		return { 8, 1 };
	case TileType::LightSSquare24:
		return { 8, 2 };
	case TileType::LightSSquare2:
		return { 8, 3 };
	case TileType::BottomMidWall:
		return { 2, 6 };
	case TileType::Empty:
	default:  // NOLINT(clang-diagnostic-covered-switch-default)
		return { 0, 4 };
	}
}
