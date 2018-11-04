#include <iostream>

#include "GameScene.h"
#include "InputHandler.h"
#include "MenuScene.h"
#include "Game.h"

const std::string GameScene::mID = "GAME";

void GameScene::Update()
{
	for (std::shared_ptr<GameObject> go : mObjects)
		go->Update();

	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_1))
	{
		Game::Instance()->GetSceneMgr()->ChangeScene(std::make_shared<MenuScene>());
	}

	if (InputHandler::Instance()->GetMouseBtnState(MouseButtons::LEFT))
	{
		std::cout << "Left Mouse Button pressed!\n";
	}
	if (InputHandler::Instance()->GetMouseBtnState(MouseButtons::MIDDLE))
	{
		std::cout << "Middle Mouse Button pressed!\n";
	}
	if (InputHandler::Instance()->GetMouseBtnState(MouseButtons::RIGHT))
	{
		std::cout << "Right Mouse Button pressed!\n";
	}
}

void GameScene::Render()
{
	for (std::shared_ptr<GameObject> go : mObjects)
		go->Draw();
}

bool GameScene::OnEnter()
{
	std::cout << "Entering Game Scene\n";
	mObjects.push_back(std::make_shared<Player>(std::make_shared<LoaderParams>(Vector2D(228, 50), Vector2D(184, 325), "walk")));
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
