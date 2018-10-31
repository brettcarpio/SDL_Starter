#pragma once
#include <string>

#include "SDL_render.h"
#include "GameObject.h"

class Scene {
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual std::string GetID() const = 0;

protected:
	std::vector<GameObject*> mObjects;
};