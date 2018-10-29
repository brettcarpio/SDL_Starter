#include <SDL_timer.h>
#include "Player.h"

Player::Player(const LoaderParams* pParams) : GameObject(pParams)
{
}

Player::~Player()
{
}

void Player::Draw(SDL_Renderer *renderer)
{
	GameObject::Draw(renderer);
}

void Player::Update()
{
	mColumn = int(((SDL_GetTicks() / 100) % 8));
}

void Player::Clean()
{
}
