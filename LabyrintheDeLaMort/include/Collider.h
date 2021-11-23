#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
protected:
	sf::RectangleShape env_collision_box_;
public:
	Collider() = default;
	explicit Collider(sf::RectangleShape env_collision_box);

	sf::RectangleShape get_env_collision_box() const;
};
