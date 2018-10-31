#include <iostream>

#include "InputHandler.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "Game.h"
#include "Button.h"

const std::string MenuScene::mID = "MENU";

void MenuScene::Update()
{
	for (GameObject *go : mObjects)
		go->Update();

	if (InputHandler::Instance()->IsKeyDown(SDL_SCANCODE_1))
	{
		Game::Instance()->GetSceneMgr()->ChangeScene(new GameScene());
	}
}

void MenuScene::Render()
{
	for (GameObject *go : mObjects)
		go->Draw();
}

bool MenuScene::OnEnter()
{
	std::cout << "Entering Main Menu\n";
	mObjects.push_back(new Button(new LoaderParams(Vector2D(225, 215), Vector2D(190, 49), "button")));
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
