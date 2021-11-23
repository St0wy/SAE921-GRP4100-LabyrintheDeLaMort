#include "Collider.h"

#include <utility>

Collider::Collider(sf::RectangleShape env_collision_box)
	: env_collision_box_(std::move(env_collision_box))
{
}

sf::RectangleShape Collider::get_env_collision_box() const
{
	return env_collision_box_;
}
