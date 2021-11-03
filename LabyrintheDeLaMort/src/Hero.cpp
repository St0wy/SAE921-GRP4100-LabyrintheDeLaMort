#include "Hero.h"

#include <iostream>
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

void Hero::decrement_luck()
{
	luck_--;
}

void Hero::set_luck(const int luck)
{
	luck_ = luck;
}

void Hero::fight(Creature& creature)
{
	const std::uniform_int_distribution distrib(2, 12);

	const int attack_force_hero = dexterity_ + distrib(gen_);
	const int attack_force_creature = creature.get_dexterity() + distrib(gen_);

	if (attack_force_hero > attack_force_creature)
	{
		int attack_strength = 2;
		char choice;
		std::cout << "Vous attaquez la creature." << std::endl;
		std::cout << "Voullez-vous tenter votre chance ? [o/n]" << std::endl;
		std::cin >> choice;
		if (choice == 'o')
		{
			attack_strength += is_lucky() ? 2 : -1;
			decrement_luck();
		}

		creature.recieve_damage(attack_strength);
	}
	else if (attack_force_creature > attack_force_hero)
	{
		int attack_strength = 2;
		char choice;
		std::cout << "Vous etes attaque par la creature." << std::endl;
		std::cout << "Voullez-vous tenter votre chance ? [o/n]" << std::endl;
		std::cin >> choice;
		if (choice == 'o')
		{
			attack_strength += is_lucky() ? -1 : 1;
			decrement_luck();
		}

		recieve_damage(attack_strength);
	}
}

bool Hero::is_lucky() const
{
	const std::uniform_int_distribution distrib(2, 12);
	return distrib(gen_) <= get_luck();
}

