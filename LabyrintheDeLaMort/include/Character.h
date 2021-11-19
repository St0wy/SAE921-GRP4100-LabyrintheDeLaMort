#pragma once
#include <random>

#include "Entity.h"

class Character : public Entity
{
protected:
	std::default_random_engine& gen_;
	int base_dexterity_;
	int base_endurance_;
	int endurance_;
	int dexterity_;
public:
	explicit Character(std::default_random_engine& gen);
	Character(std::string name, int dexterity, int endurance, std::default_random_engine& gen);

	[[nodiscard]] int get_base_dexterity() const;
	[[nodiscard]] int get_dexterity() const;
	void set_dexterity(int dexterity);

	[[nodiscard]] int get_base_endurance() const;
	[[nodiscard]] int get_endurance() const;
	void set_endurance(int endurance);
	void recieve_damage(int damage);
};
