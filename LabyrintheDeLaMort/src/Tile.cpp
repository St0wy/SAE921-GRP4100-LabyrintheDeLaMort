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
	case TileType::Gold:
		return{0,0};
	case TileType::Barrel:
		return{1,0};
	case TileType::Shelf:
		return{2,0};
	case TileType::GreenBanner:
		return{3,0};
	case TileType::RedBanner:
		return{4,0};
	case TileType::Key:
		return{5,0};
	case TileType::GreenPotion:
		return{6,0};
	case TileType::RedPotion:
		return{7,0};
	case TileType::YellowPotion:
		return{8,0};
	case TileType::GreenTableLeft:
		return {0,1};
	case TileType::GreenTableRight:
		return{1,1};
	case TileType::Skeleton:
		return{4,1};
	case TileType::RedTable:
		return{5,1};
	case TileType::HorizontalLines:
		return{0,3};
	case TileType::Stairs:
		return{1,3};
	case TileType::BottomLeftWall:
		return{3,4};
	case TileType::BottomRightWall:
		return{4,4};
	case TileType::Wall1:
		return{6,4};
	case TileType::Wall2:
		return{7,4};
	case TileType::Wall3:
		return{8,4};
	case TileType::LeftWall:
		return{3,5};
	case TileType::RightWall:
		return{4,5};
	case TileType::Wall4:
		return{6,5};
	case TileType::Wall5:
		return{7,5};
	case TileType::Wall6:
		return{8,5};
	case TileType::BottomCornerLeftWall:
		return{1,6};
	case TileType::BottomWall:
		return{2,6};
	case TileType::LeftWall2:
		return{3,6};
	case TileType::RightWall2:
		return{4,6};
	case TileType::UpperWall2:
		return{5,6};
	case TileType::UpperWall3:
		return{7,6};
	case TileType::UpperWall4:
		return{ 8,6 };
	case TileType::LeftAndBottomWall:
		return{1,7};
	case TileType::BottomWall2:
		return{2,7};
	case TileType::BottomAndRightWall:
		return{3,7};
	}
}
