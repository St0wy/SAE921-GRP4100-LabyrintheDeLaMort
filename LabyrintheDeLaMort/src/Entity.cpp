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
	if (texture_file_name.length() > 0)
	{
		texture_.loadFromFile(texture_file_name);
		sprite_.setTexture(texture_);
	}
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
