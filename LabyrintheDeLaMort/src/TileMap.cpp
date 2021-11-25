#include "TileMap.h"

constexpr int NUMBER_VERT_SQUARE = 4;

bool TileMap::load(const std::string& tileset_path, const sf::Vector2u tile_size, const Map2D& map, const std::size_t width,
	const std::size_t height)
{
	// Load the tileset texture
	if (!tileset_.loadFromFile(tileset_path))
	{
		return false;
	}

	// Resize the vertex array to fit the level size
	vertices_.setPrimitiveType(sf::Quads);
	vertices_.resize(width * height * NUMBER_VERT_SQUARE);

	// Populate the vertex array
	for (std::size_t i = 0; i < width; ++i)
	{
		for (std::size_t j = 0; j < height; ++j)
		{
			// Get the current tile number
			Tile tile = map.at(i, j);

			// Find its position in the tileset texture
			const sf::Vector2i pos = tile.get_tile_pos();

			// Get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices_[i + j * width * NUMBER_VERT_SQUARE];

			// Define its 4 corners
			quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
			quad[1].position = sf::Vector2f((i + 1) * tile_size.x, j * tile_size.y);
			quad[2].position = sf::Vector2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
			quad[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y);

			// Define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(pos.x * tile_size.x, j * tile_size.y);
			quad[1].texCoords = sf::Vector2f((pos.x + 1) * tile_size.x, j * tile_size.y);
			quad[2].texCoords = sf::Vector2f((pos.x + 1) * tile_size.x, (j + 1) * tile_size.y);
			quad[3].texCoords = sf::Vector2f(pos.x * tile_size.x, (j + 1) * tile_size.y);
		}
	}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &tileset_;
	target.draw(vertices_, states);
}
