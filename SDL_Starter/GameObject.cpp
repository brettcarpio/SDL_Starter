#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(const LoaderParams *pParams) : Object(pParams)
{
	mPosition.Set(pParams->GetPos());
	mSize.Set(pParams->GetSize());
	mTextureID = pParams->GetTextureID();
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
