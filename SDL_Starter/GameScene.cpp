#include <iostream>

#include "GameScene.h"
#include "InputHandler.h"
#include "MenuScene.h"
#include "Game.h"

const std::string GameScene::mID = "GAME";

void GameScene::Update()
{
	for (GameObject *go : mObjects)
		go->Update();

	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_0))
	{
		Game::Instance()->GetSceneMgr()->ChangeScene(new MenuScene());
	}
}

void GameScene::Render()
{
	for (GameObject *go : mObjects)
		go->Draw();
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
