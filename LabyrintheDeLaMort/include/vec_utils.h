#pragma once
#include <SFML/Graphics.hpp>

template<typename T>
void normalize(sf::Vector2<T>& vec)
{
	T length = vec_length<T>(vec);

	if (length != 0.0)
	{
		vec /= length;
	}
}

template<typename T>
T vec_length(const sf::Vector2<T>& vec)
{
	return std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
}
