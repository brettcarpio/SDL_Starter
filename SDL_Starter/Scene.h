#pragma once
#include <string>

#include "SDL_render.h"

class Scene {
public:
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer *renderer) = 0;

	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual std::string GetID() const = 0;
};