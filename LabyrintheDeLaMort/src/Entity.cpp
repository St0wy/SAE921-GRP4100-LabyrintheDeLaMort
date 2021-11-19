#include "Entity.h"

#include <utility>

Entity::Entity()
	: Entity("NO NAME")
{
}

Entity::Entity(std::string name)
	: name_(std::move(name))
{
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
