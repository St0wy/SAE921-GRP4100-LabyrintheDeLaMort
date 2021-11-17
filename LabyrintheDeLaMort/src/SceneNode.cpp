#include "SceneNode.h"

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply this object/node's transform (position, rotation, etc.)
	states.transform *= getTransform();

	// Draw this object
	on_draw(target, states);

	// Draw all children
	for (const auto& child : children_)
		child->draw(target, states);
}
