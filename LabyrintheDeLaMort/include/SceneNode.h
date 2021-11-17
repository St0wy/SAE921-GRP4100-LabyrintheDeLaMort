#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SceneNode
	: public sf::Drawable, public sf::Transformable
{
private:
	std::vector<std::unique_ptr<SceneNode>> children_;
public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	virtual void on_draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};