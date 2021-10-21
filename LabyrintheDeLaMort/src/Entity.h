#pragma once
#include <random>
#include <string>

class Entity
{
private:
	std::string name_;
	int dexterity_;
	int endurance_;
	std::default_random_engine& gen_;

public:
	static constexpr int DEFAULT_DAMAGE = 2;

	explicit Entity(std::default_random_engine& gen);
	Entity(std::string name, int dexterity, int endurance, std::default_random_engine& gen);

	void recieve_damage(int damage);
};

