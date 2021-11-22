#include <iostream>
#include <utility>

#include "Hero.h"
#include "VecUtils.h"
#include "Consts.h"

Hero::Hero(std::default_random_engine& gen)
	: Hero("", 0, 0, gen, 0, std::vector<Jewel>(),
		0, std::vector<std::unique_ptr<Item>>(), nullptr, nullptr)
{
}

Hero::Hero(std::string name, const int dexterity, const int endurance, std::default_random_engine& gen, const int luck,
	std::vector<Jewel> jewels, const int gold, std::vector<std::unique_ptr<Item>> items, std::unique_ptr<Weapon> weapon,
	std::unique_ptr<Armor> armor)
	: Character(std::move(name), dexterity, endurance, gen),
	base_luck_(luck),
	luck_(luck),
	jewels_(std::move(jewels)),
	gold_(gold),
	items_(std::move(items)),
	weapon_(std::move(weapon)),
	armor_(std::move(armor)),
	state_(HeroState::Idle),
	idle_(get_sprite(), 0.6f),
	walk_(get_sprite(), 0.6f)
{
	for (int i = 0; i < 6; ++i)
	{
		idle_.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80), SPRITE_SIZE));
		walk_.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80 + SPRITE_SIZE.x), SPRITE_SIZE));
	}
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

HeroState Hero::get_state() const
{
	return state_;
}

void Hero::set_state(const HeroState state)
{
	state_ = state;
}

void Hero::fight(Creature & creature)
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

void Hero::update(const sf::Time delta_time)
{
	compute_move(delta_time);

	switch (get_state())
	{
	case HeroState::Idle:
		idle_.update(delta_time.asSeconds());
		break;
	case HeroState::Walk:
		walk_.update(delta_time.asSeconds());
		break;
	}
}

void Hero::compute_move(const sf::Time delta_time)
{
	sf::Vector2f movement;
	set_state(HeroState::Idle);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement += sf::Vector2f(0, -1);
		set_state(HeroState::Walk);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement += sf::Vector2f(0, 1);
		set_state(HeroState::Walk);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement += sf::Vector2f(-1, 0);
		set_state(HeroState::Walk);
		setScale(-1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement += sf::Vector2f(1, 0);
		set_state(HeroState::Walk);
		setScale(1, 1);
	}

	normalize(movement);

	movement *= SPEED * delta_time.asSeconds();

	this->move(movement);
}
