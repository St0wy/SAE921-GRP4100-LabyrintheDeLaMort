#pragma once
#include <random>
#include <string>
#include <SFML/Graphics.hpp>


class Entity
{
protected:
	std::string name_;
	int base_dexterity_;
	int base_endurance_;
	int endurance_;
	int dexterity_;
	std::default_random_engine& gen_;
	sf::Texture texture_;
	sf::Sprite sprite_;

public:
	static constexpr int DEFAULT_DAMAGE = 2;

	explicit Entity(std::default_random_engine& gen);
	Entity(std::string name, int dexterity, int endurance, std::default_random_engine& gen, const std::string&
	       texture_file_name);

	[[nodiscard]] int get_base_dexterity() const;
	[[nodiscard]] int get_dexterity() const;
	void set_dexterity(int dexterity);

	[[nodiscard]] int get_base_endurance() const;
	[[nodiscard]] int get_endurance() const;
	void set_endurance(int endurance);

	void set_texture(const std::string& texture_file_name);
	sf::Sprite& get_sprite();
	sf::Vector2f get_texture_center() const;

	void recieve_damage(int damage);
};

