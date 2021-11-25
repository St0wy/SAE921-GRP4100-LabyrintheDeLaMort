#pragma once
#include "TileType.h"

constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";

const sf::Vector2u SPRITE_SIZE(16, 16);
const sf::Vector2u MAP_SIZE(16, 9);
constexpr int WINDOW_SCALE = 5;
constexpr int CAM_SIZE_X = 16 * 16;
constexpr int CAM_SIZE_Y = 16 * 9;
constexpr int WINDOW_WIDTH = CAM_SIZE_X * WINDOW_SCALE;
constexpr int WINDOW_HEIGHT = CAM_SIZE_Y * WINDOW_SCALE;

constexpr char TILEMAP_PATH[] = "./data/sprites/world_tilemap.png";
constexpr char SPRITESHEET_PATH[] = "./data/sprites/char_spritesheet.png";

constexpr std::size_t MAP_WIDTH = 2;
constexpr std::size_t MAP_HEIGHT = 2;
constexpr TileType MAP_LAYOUT[] = {
	TileType::DirtOne, TileType::DirtTwo,
	TileType::HSquareE, TileType::SSquare,
};

