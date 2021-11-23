#pragma once
#include "Entity.h"
#include "Collider.h"

class Wall final
	: public Entity, public Collider
{
public:
	void update(sf::Time delta_time) override;
};

inline void Wall::update(sf::Time delta_time)
{
}
