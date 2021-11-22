#pragma once

constexpr int FRAMERATE = 60;
constexpr char WINDOW_NAME[] = "Labyrinthe de la mort";

const sf::Vector2i SPRITE_SIZE(16, 16);
constexpr int WINDOW_SCALE = 5;
constexpr int CAM_SIZE_X = 16 * 16;
constexpr int CAM_SIZE_Y = 16 * 9;
constexpr int WINDOW_WIDTH = CAM_SIZE_X * WINDOW_SCALE;
constexpr int WINDOW_HEIGHT = CAM_SIZE_Y * WINDOW_SCALE;