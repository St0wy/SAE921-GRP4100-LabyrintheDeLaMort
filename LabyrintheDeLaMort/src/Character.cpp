#include "Character.h"

Character::Character(std::default_random_engine& gen)
	: Character("NO NAME", 0, 0, gen)
{
}

Character::Character(std::string name, const int dexterity, const int endurance, std::default_random_engine& gen)
	: Entity(std::move(name)), gen_(gen), base_dexterity_(dexterity), base_endurance_(endurance), endurance_(endurance), dexterity_(dexterity)
{
}

int Character::get_base_dexterity() const
{
	return base_dexterity_;
}

int Character::get_dexterity() const
{
	return dexterity_;
}

void Character::set_dexterity(const int dexterity)
{
	dexterity_ = dexterity;
}

int Character::get_base_endurance() const
{
	return base_endurance_;
}


int Character::get_endurance() const
{
	return endurance_;
}

void Character::set_endurance(const int endurance)
{
	endurance_ = endurance;
}

void Character::recieve_damage(const int damage)
{
	endurance_ -= damage;
}
