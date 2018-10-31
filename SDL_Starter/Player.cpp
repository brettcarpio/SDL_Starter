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
}
