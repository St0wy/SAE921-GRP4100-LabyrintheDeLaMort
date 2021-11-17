#include "Entity.h"

#include <utility>

Entity::Entity(std::default_random_engine& gen)
	: Entity("", 0, 0, gen, "")
{
}

Entity::Entity(
	std::string name,
	const int dexterity,
	const int endurance,
	std::default_random_engine& gen,
	const std::string& texture_file_name)

	: name_(std::move(name)),
	base_dexterity_(dexterity),
	base_endurance_(endurance),
	endurance_(endurance),
	dexterity_(dexterity),
	gen_(gen)
{
	set_texture(texture_file_name);
}

int Entity::get_base_dexterity() const
{
	return base_dexterity_;
}

int Entity::get_dexterity() const
{
	return dexterity_;
}

void Entity::set_dexterity(const int dexterity)
{
	dexterity_ = dexterity;
}

int Entity::get_base_endurance() const
{
	return base_endurance_;
}

void Entity::set_texture(const std::string& texture_file_name)
{
	if (texture_file_name.length() > 0)
	{
		texture_.loadFromFile(texture_file_name);
		sprite_.setTexture(texture_);
		sprite_.setOrigin(get_texture_center());
	}
}

sf::Sprite& Entity::get_sprite()
{
	return sprite_;
}

sf::Vector2f Entity::get_texture_center() const
{
	sf::Vector2f texture_center(texture_.getSize());
	texture_center /= 2.0f;
	return texture_center;
}

int Entity::get_endurance() const
{
	return endurance_;
}

void Entity::set_endurance(const int endurance)
{
	endurance_ = endurance;
}

void Entity::recieve_damage(const int damage)
{
	endurance_ -= damage;
}
