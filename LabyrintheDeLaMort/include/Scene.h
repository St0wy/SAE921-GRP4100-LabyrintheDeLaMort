#pragma once

#include "SceneNode.h"
#include <vector>

class Scene
{
private:
	std::vector<std::unique_ptr<SceneNode>> children_;
public:
	explicit Scene(std::vector<std::unique_ptr<SceneNode>> children);

	void add_child(std::unique_ptr<SceneNode> child);
};