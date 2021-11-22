#pragma once
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

	Entity();
	explicit Entity(std::string name);
	Entity(Entity& entity) = delete;
	Entity(Entity&& entity) noexcept = default;
	~Entity() override = default;
	Entity& operator=(const Entity& other) = default;
	Entity& operator=(Entity&& other) noexcept = default;

	void set_texture(const sf::Texture& texture, const sf::IntRect& texture_rect);
	sf::Sprite& get_sprite();

	virtual void update(sf::Time delta_time) = 0;

	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

