#pragma once

enum class TileType
{
	Empty,

	//ligne1
	Gold,
	Barrel,
	Shelf,
	GreenBanner,
	RedBanner,
	Key,
	GreenPotion,
	RedPotion,
	YellowPotion,

	//ligne2
	GreenTableLeft,
	GreenTableRight,
	Skeleton,
	RedTable,

	//ligne4
	HorizontalLines,
	Stairs,

	//ligne5
	BottomLeftWall,
	BottomRightWall,
	Wall1,
	Wall2,
	Wall3,

	//ligne6
	LeftWall,
	RightWall,
	Wall4,
	Wall5,
	Wall6,

	//ligne7
	BottomCornerLeftWall,
	BottomWall,
	LeftWall2,
	RightWall2,
	UpperWall2,
	UpperWall3,
	UpperWall4,

	//ligne8
	LeftAndBottomWall,
	BottomWall2,
	BottomAndRightWall,

	//other
	DirtOne,
	DirtTwo,
	BSquare,
	HSquareE,
	HSquareW,
	SSquare,
	ThreeSSquare,
	HalfSSquare,
	SSquareTransiN,
	SSquareTransiS,
	SSquareTransiE,
	SSquareTransiW,
	LightSSquare1,
	LightSSquare13,
	LightSSquare123,
	LightSSquare12,
	LightSSquare124,
	LightSSquare24,
	LightSSquare2,
	BottomMidWall,
};
