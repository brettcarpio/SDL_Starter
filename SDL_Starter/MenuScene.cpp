#include <iostream>

#include "InputHandler.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "Game.h"

const std::string MenuScene::mID = "MENU";

void MenuScene::Update()
{
	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_1))
	{
		Game::Instance()->GetSceneMgr()->ChangeScene(new GameScene());
	}
}

void MenuScene::Render()
{
}

bool MenuScene::OnEnter()
{
	std::cout << "Entering Main Menu\n";
	return false;
}

bool MenuScene::OnExit()
{
	std::cout << "Exiting Main Menu\n";
	return false;
}

std::string MenuScene::GetID() const
{
	return mID;
}
