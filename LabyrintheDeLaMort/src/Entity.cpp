#include "Entity.h"

#include <utility>

Entity::Entity(std::default_random_engine& gen)
	: Entity("", 0, 0, gen)
{
}

Entity::Entity(std::string name, const int dexterity, const int endurance, std::default_random_engine& gen)
	: name_(std::move(name)), dexterity_(dexterity), endurance_(endurance), gen_(gen)
{
}

void Entity::recieve_damage(const int damage)
{
	endurance_ -= damage;
}
