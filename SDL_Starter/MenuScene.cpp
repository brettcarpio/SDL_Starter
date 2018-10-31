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
}

void MenuScene::Render()
{
	for (GameObject *go : mObjects)
		go->Draw();
}

bool MenuScene::OnEnter()
{
	std::cout << "Entering Main Menu\n";
	mObjects.push_back(new Button(new LoaderParams(Vector2D(225, 215), Vector2D(190, 49), "button"), mMenuToGame));
	return true;
}

bool MenuScene::OnExit()
{
	std::cout << "Exiting Main Menu\n";
	return true;
}

std::string MenuScene::GetID() const
{
	return mID;
}

void MenuScene::mMenuToGame()
{
	std::cout << "Button Clicked!\n";
	Game::Instance()->GetSceneMgr()->ChangeScene(new GameScene());
}
