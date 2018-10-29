#include <iostream>

#include "GameScene.h"

const std::string GameScene::mID = "GAME";

void GameScene::Update()
{
	for (GameObject *go : mObjects)
		go->Update();
}

void GameScene::Render(SDL_Renderer *renderer)
{
	for (GameObject *go : mObjects)
		go->Draw(renderer);
}

bool GameScene::OnEnter()
{
	std::cout << "Entering Game Scene\n";
	mObjects.push_back(new Player(new LoaderParams(Vector2D(100, 50), Vector2D(184, 325), "walk")));
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
