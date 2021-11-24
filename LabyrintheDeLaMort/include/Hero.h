#pragma once
#include <vector>
#include <memory>

#include "Entity.h"
#include "Jewel.h"
#include "Weapon.h"
#include "Armor.h"
#include "Creature.h"
#include "HeroState.h"
#include "Character.h"
#include "FrameAnimation.h"
#include "Wall.h"

class Hero final :
	public Character
{
private:
	int base_luck_;
	int luck_;
	std::vector<Jewel> jewels_;
	int gold_;
	std::vector<std::unique_ptr<Item>> items_;
	std::unique_ptr<Weapon> weapon_;
	std::unique_ptr<Armor> armor_;
	HeroState state_;
	FrameAnimation idle_;
	FrameAnimation walk_;
	std::vector<Wall*> walls_;
	sf::RectangleShape env_collision_box_;
public:
	static constexpr float SPEED = 100.0f;

	explicit Hero(std::default_random_engine& gen);
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

	HeroState get_state() const;
	void set_state(HeroState state);

	void add_wall(Wall* wall);

	void fight(Creature& creature);
	bool is_lucky() const;
	void update(sf::Time delta_time) override;
	sf::Vector2f compute_move(sf::Time delta_time);
	void apply_movement(sf::Vector2f movement);
	sf::FloatRect get_global_bounds() const;
	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

