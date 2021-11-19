#pragma once
#include <random>
#include <string>
#include <SFML/Graphics.hpp>

#include "SceneNode.h"

class Entity : public SceneNode
{
protected:
	std::string name_;
	sf::Sprite sprite_;

public:
	static constexpr int DEFAULT_DAMAGE = 2;

	explicit Entity();
	Entity(std::string name);

	void set_texture(const sf::Texture& texture, const sf::IntRect& texture_rect);
	sf::Sprite& get_sprite();

	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

