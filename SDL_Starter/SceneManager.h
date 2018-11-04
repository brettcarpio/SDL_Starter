#pragma once

#include <memory>
#include <vector>
#include "Scene.h"

class SceneManager {
public:
	void PushScene(std::shared_ptr<Scene> scene);
	void ChangeScene(std::shared_ptr<Scene> scene);
	void PopScene();

	void Update();
	void Render();

private:
	std::vector<std::shared_ptr<Scene>> mScenes;
};