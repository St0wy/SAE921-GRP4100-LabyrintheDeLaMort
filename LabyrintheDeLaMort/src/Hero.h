#pragma once
#include <vector>
#include <memory>

#include "Entity.h"
#include "Jewel.h"
#include "Weapon.h"
#include "Armor.h"

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
	// TODO : Make constructors

	[[nodiscard]] int get_base_luck() const;
	[[nodiscard]] int get_luck() const;
	void increment_base_luck();
	void set_luck(int luck);
};

