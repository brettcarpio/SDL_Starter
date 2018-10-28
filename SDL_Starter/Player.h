#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(const LoaderParams *pParams);
	~Player();

private:
	void Draw(SDL_Renderer *renderer);
	void Update();
	void Clean();
};