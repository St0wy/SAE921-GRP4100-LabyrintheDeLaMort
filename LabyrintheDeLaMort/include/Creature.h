#pragma once
#include "Character.h"

class Creature final :
	public Character
{
public:
	explicit Creature(std::default_random_engine& gen)
		: Character(gen)
	{
	}

	Creature(const std::string& name, const int dexterity, const int endurance, std::default_random_engine& gen)
		: Character(name, dexterity, endurance, gen)
	{
	}
};

