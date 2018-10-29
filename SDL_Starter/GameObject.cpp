#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const LoaderParams *pParams) : Object(pParams)
{
	mPosition.set(pParams->GetPos());
	mSize.set(pParams->GetSize());
	mTextureID = pParams->GetTextureID();
	mRow = 1;
	mColumn = 1;
}

void GameObject::Draw(SDL_Renderer *renderer)
{
	TextureManager::GetInstance()->DrawFrame(mTextureID, mPosition, mSize, mRow, mColumn, renderer);
}

void GameObject::Update()
{
}

void GameObject::Clean()
{
}
