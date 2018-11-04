#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(const std::shared_ptr<LoaderParams> pParams);
	~Player();

private:
	void Draw();
	void Update();
	void Clean();
	void HandleInput();
};