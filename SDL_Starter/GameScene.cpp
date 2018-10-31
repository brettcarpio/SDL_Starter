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

	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_1))
	{
		Game::Instance()->GetSceneMgr()->ChangeScene(new MenuScene());
	}

	if (InputHandler::Instance()->GetMouseBtnState(0))
	{
		std::cout << "Mouse Button 0 pressed!\n";
	}
	if (InputHandler::Instance()->GetMouseBtnState(1))
	{
		std::cout << "Mouse Button 1 pressed!\n";
	}
	if (InputHandler::Instance()->GetMouseBtnState(2))
	{
		std::cout << "Mouse Button 2 pressed!\n";
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
	mObjects.push_back(new Player(new LoaderParams(Vector2D(228, 50), Vector2D(184, 325), "walk")));
	return true;
}

bool GameScene::OnExit()
{
	std::cout << "Exiting Game Scene\n";
	return true;
}

std::string GameScene::GetID() const
{
	return mID;
}
