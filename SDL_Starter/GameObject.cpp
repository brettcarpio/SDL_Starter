#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(const LoaderParams *pParams) : Object(pParams)
{
	mPosition.set(pParams->GetPos());
	mSize.set(pParams->GetSize());
	mTextureID = pParams->GetTextureID();
	mRow = 1;
	mColumn = 1;
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
