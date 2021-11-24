#include "Wall.h"

Wall::Wall()
	: env_collision_box_(sf::Vector2f(16, 8))
{
	env_collision_box_.setPosition(-8, 0);
}

sf::RectangleShape Wall::get_env_collision_box() const
{
	return env_collision_box_;
}

void Wall::update(sf::Time delta_time)
{
}

void Wall::on_draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	Entity::on_draw(target, states);
	//target.draw(env_collision_box_, states);
}

sf::FloatRect Wall::get_global_bounds() const
{
	auto global_bounds = env_collision_box_.getGlobalBounds();
	global_bounds.left += getPosition().x;
	global_bounds.top += getPosition().y;
	return global_bounds;
}