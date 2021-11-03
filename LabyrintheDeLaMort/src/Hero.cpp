#include "Hero.h"

#include <utility>

Hero::Hero(std::default_random_engine& gen)
	: Entity(gen),
	base_luck_(0),
	luck_(0),
	jewels_(std::vector<Jewel>()),
	gold_(0),
	items_(std::vector<std::unique_ptr<Item>>()),
	weapon_(nullptr),
	armor_(nullptr)
{
}

Hero::Hero(std::string name, const int dexterity, const int endurance, std::default_random_engine& gen, const int luck,
	std::vector<Jewel> jewels, const int gold, std::vector<std::unique_ptr<Item>> items, std::unique_ptr<Weapon> weapon,
	std::unique_ptr<Armor> armor)
	: Entity(std::move(name), dexterity, endurance, gen),
	base_luck_(luck),
	luck_(luck),
	jewels_(std::move(jewels)),
	gold_(gold),
	items_(std::move(items)),
	weapon_(std::move(weapon)),
	armor_(std::move(armor))
{
}

int Hero::get_base_luck() const
{
	return base_luck_;
}

int Hero::get_luck() const
{
	return luck_;
}

void Hero::increment_base_luck()
{
	base_luck_++;
}

void Hero::set_luck(const int luck)
{
	luck_ = luck;
}
