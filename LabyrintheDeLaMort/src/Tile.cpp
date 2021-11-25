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
		return { 80, 48 };
	case TileType::DirtTwo:
		return { 80, 32 };
	case TileType::BSquare:
		return { 48, 16 };
	case TileType::HSquareE:
		return { 0, 32 };
	case TileType::HSquareW:
		return { 16, 32 };
	case TileType::SSquare:
		return { 32, 16 };
	case TileType::ThreeSSquare:
		return { 32, 32 };
	case TileType::HalfSSquare:
		return { 48, 32 };
	case TileType::SSquareTransiN:
		return { 64, 32 };
	case TileType::SSquareTransiS:
		return { 64, 48 };
	case TileType::SSquareTransiE:
		return { 48, 48 };
	case TileType::SSquareTransiW:
		return { 32, 48 };
	case TileType::LightSSquare1:
		return { 96, 48 };
	case TileType::LightSSquare13:
		return { 96, 32 };
	case TileType::LightSSquare123:
		return { 96, 16 };
	case TileType::LightSSquare12:
		return { 112, 16 };
	case TileType::LightSSquare124:
		return { 128, 16 };
	case TileType::LightSSquare24:
		return { 128, 32 };
	case TileType::LightSSquare2:
		return { 128, 48 };
	case TileType::Empty:
	default:  // NOLINT(clang-diagnostic-covered-switch-default)
		return { 0, 64 };
	}
}
