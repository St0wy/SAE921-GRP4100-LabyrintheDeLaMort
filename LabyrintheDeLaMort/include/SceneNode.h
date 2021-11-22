#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SceneNode
	: public sf::Drawable, public sf::Transformable
{
private:
	std::vector<std::unique_ptr<SceneNode>> children_;
public:
	SceneNode() = default;
	SceneNode(SceneNode& entity) = default;
	SceneNode(SceneNode&& entity) noexcept = default;
	~SceneNode() override = default;
	SceneNode& operator=(const SceneNode& other) = default;
	SceneNode& operator=(SceneNode&& other) noexcept = default;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	virtual void on_draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};