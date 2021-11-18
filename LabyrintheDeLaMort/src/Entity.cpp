#include "Entity.h"

#include <utility>

const sf::Vector2i HERO_SIZE(16, 16);

Entity::Entity(std::default_random_engine& gen)
	: Entity("", 0, 0, gen)
{
}

Entity::Entity(
	std::string name,
	const int dexterity,
	const int endurance,
	std::default_random_engine& gen)
	: name_(std::move(name)),
	base_dexterity_(dexterity),
	base_endurance_(endurance),
	endurance_(endurance),
	dexterity_(dexterity),
	gen_(gen)
{
}

int Entity::get_base_dexterity() const
{
	return base_dexterity_;
}

int Entity::get_dexterity() const
{
	return dexterity_;
}

void Entity::set_dexterity(const int dexterity)
{
	dexterity_ = dexterity;
}

int Entity::get_base_endurance() const
{
	return base_endurance_;
}

void Entity::set_texture(const sf::Texture& texture, const sf::IntRect& texture_rect)
{
	sprite_.setTextureRect(texture_rect);
	sprite_.setTexture(texture);
	//sprite_.setScale(WINDOW_SCALE, WINDOW_SCALE);

	const float x_center = static_cast<float>(texture_rect.width) / 2.0f;
	const float y_center = static_cast<float>(texture_rect.height) / 2.0f;
	sprite_.setOrigin(x_center, y_center);
}

sf::Sprite& Entity::get_sprite()
{
	return sprite_;
}

void Entity::on_draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	target.draw(sprite_, states);
}

int Entity::get_endurance() const
{
	return endurance_;
}

void Entity::set_endurance(const int endurance)
{
	endurance_ = endurance;
}

void Entity::recieve_damage(const int damage)
{
	endurance_ -= damage;
}
