#pragma once
#include <SFML/Graphics/Rect.hpp>

struct Frame
{
	float relative_duration;
	sf::IntRect subrect;
	sf::Vector2f origin;
	bool apply_origin;

	Frame(const float duration, const sf::IntRect& subrect)
		: relative_duration(duration), subrect(subrect), apply_origin(false)
	{
	}

	Frame(const float duration, const sf::IntRect& subrect, const sf::Vector2f origin)
	: relative_duration(duration), subrect(subrect), origin(origin), apply_origin(true)
	{
	}
};
