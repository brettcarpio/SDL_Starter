#include <iostream>

#include "MenuScene.h"

const std::string MenuScene::mID = "MENU";

void MenuScene::Update()
{
}

void MenuScene::Render(SDL_Renderer *renderer)
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
