#include <iostream>

#include "GameScene.h"

const std::string GameScene::mID = "GAME";

void GameScene::Update()
{

}

void GameScene::Render(SDL_Renderer *renderer)
{

}

bool GameScene::OnEnter()
{
	std::cout << "Entering Game Scene\n";
	return false;
}

bool GameScene::OnExit()
{
	std::cout << "Exiting Game Scene\n";
	return false;
}

std::string GameScene::GetID() const
{
	return mID;
}
