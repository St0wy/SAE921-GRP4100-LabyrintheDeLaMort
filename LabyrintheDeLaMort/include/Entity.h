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

	/**
	 * \brief Sets the texture of the entity.
	 * \param texture Texture to apply to the entity.
	 * \param texture_rect Rectangle that will be used as the texture.
	 */
	void set_texture(const sf::Texture& texture, const sf::IntRect& texture_rect);

	/**
	 * \brief Gets the sprite of the Entity.
	 * \return The sprite of the Entity.
	 */
	sf::Sprite& get_sprite();

	/**
	 * \brief Updates the entity. Should be implemented by child classes.
	 * \param delta_time Time elapsed since the last frame.
	 */
	virtual void update(sf::Time delta_time) = 0;

	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

