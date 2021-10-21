#pragma once
#include <random>
#include <string>

class Entity
{
private:
	std::string name_;
	int base_dexterity_;
	int dexterity_;
	int base_endurance_;
	int endurance_;
	std::default_random_engine& gen_;

public:
	static constexpr int DEFAULT_DAMAGE = 2;

	explicit Entity(std::default_random_engine& gen);
	Entity(std::string name, int dexterity, int endurance, std::default_random_engine& gen);

	[[nodiscard]] int get_base_dexterity() const;
	[[nodiscard]] int get_dexterity() const;
	void set_dexterity(int dexterity);

	[[nodiscard]] int get_base_endurance() const;
	[[nodiscard]] int get_endurance() const;
	int set_endurance(int endurance);

	void recieve_damage(int damage);
};

