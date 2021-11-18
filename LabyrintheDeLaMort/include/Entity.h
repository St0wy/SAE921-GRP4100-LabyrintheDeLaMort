#pragma once
#include <random>
#include <string>
#include <SFML/Graphics.hpp>

#include "SceneNode.h"

class Entity : public SceneNode
{
protected:
	std::string name_;
	int base_dexterity_;
	int base_endurance_;
	int endurance_;
	int dexterity_;
	std::default_random_engine& gen_;
	sf::Sprite sprite_;

public:
	static constexpr int DEFAULT_DAMAGE = 2;

	explicit Entity(std::default_random_engine& gen);
	Entity(std::string name, int dexterity, int endurance, std::default_random_engine& gen);

	[[nodiscard]] int get_base_dexterity() const;
	[[nodiscard]] int get_dexterity() const;
	void set_dexterity(int dexterity);

	[[nodiscard]] int get_base_endurance() const;
	[[nodiscard]] int get_endurance() const;
	void set_endurance(int endurance);

	void set_texture(const sf::Texture& texture, const sf::IntRect& texture_rect);
	sf::Sprite& get_sprite();

	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void recieve_damage(int damage);
};

