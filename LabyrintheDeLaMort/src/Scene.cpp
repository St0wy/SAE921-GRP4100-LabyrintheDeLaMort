#include "Scene.h"

Scene::Scene(std::vector<std::unique_ptr<SceneNode>> children)
	:children_(std::move(children))
{
}

void Scene::add_child(std::unique_ptr<SceneNode> child)
{
	children_.emplace_back(std::move(child));
}
