#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(const std::shared_ptr<LoaderParams> params) : Object(params)
{
	mPosition.Set(params->GetPos());
	mSize.Set(params->GetSize());
	mTextureID = params->GetTextureID();
	mRow = 1;
	mColumn = 0;
}

void GameObject::Draw()
{
	TextureManager::Instance()->DrawFrame(mTextureID, mPosition, mSize, mRow, mColumn, Game::Instance()->GetRenderer());
}

void GameObject::Update()
{
}

void GameObject::Clean()
{
}
