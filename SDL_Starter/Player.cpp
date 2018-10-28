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
}

void Player::Clean()
{
}
