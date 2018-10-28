#pragma once

#include <memory>
#include <vector>
#include "Scene.h"

class SceneManager {
public:
	void PushScene(Scene *scene);
	void ChangeScene(Scene *scene);
	void PopScene();

	void Update();
	void Render(SDL_Renderer *renderer);

private:
	std::vector<Scene*> mScenes;
};