#pragma once
#include "Entity.h"

class Wall final
	: public Entity
{
private:
	sf::RectangleShape env_collision_box_;
public:
	Wall();

	sf::RectangleShape get_env_collision_box() const;

	void update(sf::Time delta_time) override;
	void on_draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect get_global_bounds() const;
};
