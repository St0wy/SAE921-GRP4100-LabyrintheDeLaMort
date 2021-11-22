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

	/**
	 * \brief Draws the SceneNode and all of its children.
	 * \param target Render target to render on.
	 * \param states Transformations of the parent objects.
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	/**
	 * \brief Renders the node on the target.
	 * \param target Render target to render on.
	 * \param states Transformations of the parent objects.
	 */
	virtual void on_draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};