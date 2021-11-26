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
	walk_(get_sprite(), 0.6f),
	env_collision_box_(sf::Vector2f(6, 3))
{
	for (int i = 0; i < 6; ++i)
	{
		idle_.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80), sf::Vector2i(SPRITE_SIZE)));
		walk_.add_frame(1.0f,
			sf::IntRect(sf::Vector2i(i * SPRITE_SIZE.y, 80 + SPRITE_SIZE.x), sf::Vector2i(SPRITE_SIZE)));
	}
	env_collision_box_.setPosition(-2, 3);
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

//void Hero::add_wall(Wall* wall)
//{
//	walls_.emplace_back(wall);
//}

void Hero::fight(Creature& creature)
{
	const std::uniform_int_distribution distrib(2, 12);

	const int attack_force_hero = dexterity_ + distrib(gen_);
	// ReSharper disable once CppTooWideScopeInitStatement
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
	const sf::Vector2f movement = compute_move(delta_time);

	bool is_colliding = false;

	sf::RectangleShape collision_copy = env_collision_box_;
	collision_copy.move(getPosition());
	collision_copy.move(movement);
	//for (const auto& wall : walls_)
	//{
	//	// TODO : Fix collision
	//	auto shape_bounds = collision_copy.getGlobalBounds();
	//	auto wall_bounds = wall->get_global_bounds();
	//	if (shape_bounds.intersects(wall_bounds))
	//	{
	//		is_colliding = true;
	//		break;
	//	}
	//}

	/*if (!is_colliding)
	{
	}*/
	apply_movement(movement);

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

sf::Vector2f Hero::compute_move(const sf::Time delta_time)
{
	sf::Vector2f movement;
	set_state(HeroState::Idle);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement += sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement += sf::Vector2f(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement += sf::Vector2f(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement += sf::Vector2f(1, 0);
	}

	normalize(movement);

	movement *= SPEED * delta_time.asSeconds();
	return movement;
}

void Hero::apply_movement(const sf::Vector2f movement)
{
	move(movement);
	if (movement == sf::Vector2f(0, 0))
	{
		set_state(HeroState::Idle);
	}
	else
	{
		set_state(HeroState::Walk);
	}

	if (movement.x > 0)
	{
		setScale(1, 1);
	}
	else if (movement.x < 0)
	{
		setScale(-1, 1);
	}
}

sf::FloatRect Hero::get_global_bounds() const
{
	auto global_bounds = env_collision_box_.getGlobalBounds();
	global_bounds.left += this->getPosition().x;
	global_bounds.top += this->getPosition().y;
	return global_bounds;
}

void Hero::on_draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	Character::on_draw(target, states);
	//target.draw(env_collision_box_, states);
}
