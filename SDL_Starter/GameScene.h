#pragma once
#include <vector>

#include "Scene.h"
#include "GameObject.h"
#include "Player.h"

class GameScene : public Scene {
public:
	virtual void Update();
	virtual void Render(SDL_Renderer *renderer);

	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetID() const;

private:
	static const std::string mID;
	std::vector<GameObject*> mObjects;
};