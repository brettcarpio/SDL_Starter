#pragma once

#include <vector>
#include "Scene.h"

class SceneManager {
public:
	void PushScene(Scene* scene);
	void ChangeScene(Scene* scene);
	void PopScene();

private:
	std::vector<Scene*> mScenes;
};