#pragma once
#include <vector>
#include <memory>

#include "Entity.h"
#include "Jewel.h"
#include "Weapon.h"
#include "Armor.h"
#include "Creature.h"

class Hero :
	public Entity
{
private:
	int base_luck_;
	int luck_;
	std::vector<Jewel> jewels_;
	int gold_;
	std::vector<std::unique_ptr<Item>> items_;
	std::unique_ptr<Weapon> weapon_;
	std::unique_ptr<Armor> armor_;
public:
	explicit Hero(std::default_random_engine& gen);

	// TOO : Make constructors
	Hero(
		std::string name,
		int dexterity,
		int endurance,
		std::default_random_engine& gen,
		int luck,
		std::vector<Jewel> jewels,
		int gold,
		std::vector<std::unique_ptr<Item>> items,
		std::unique_ptr<Weapon> weapon,
		std::unique_ptr<Armor> armor);


	[[nodiscard]] int get_base_luck() const;
	[[nodiscard]] int get_luck() const;
	void increment_base_luck();
	void decrement_luck();
	void set_luck(int luck);
	void fight(Creature& creature);
	bool is_lucky() const;
};
