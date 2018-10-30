#include <SDL_timer.h>
#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams *pParams) : GameObject(pParams)
{
}

Player::~Player()
{
}

void Player::Draw()
{
	GameObject::Draw();
}

void Player::Update()
{
	mColumn = int(((SDL_GetTicks() / 100) % 8));
	HandleInput();
}

void Player::Clean()
{
}

void Player::HandleInput()
{
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
