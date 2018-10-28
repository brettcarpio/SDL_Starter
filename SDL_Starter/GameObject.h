#pragma once

#include <iostream>

#include "SDL_render.h"
#include "Vector2D.h"

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string
		textureID) : mFramePosition(x, y), mSize(width, height), mTextureID(textureID) {}
	Vector2D GetSize() const { return mSize; }
	Vector2D GetFramePos() const { return mFramePosition; }
	Vector2D GetPos() const { return mPosition; }
	std::string GetTextureID() const { return mTextureID; }
private:
	std::string mTextureID;
	int mRow;
	int mColumn;
	Vector2D mSize;
	Vector2D mFramePosition;
	Vector2D mPosition;
};

class Object 
{
public:
	virtual void Draw(SDL_Renderer *renderer) = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
protected:
	Object(const LoaderParams *params) {}
	virtual ~Object() {}
};

class GameObject : public Object
{
public:
	GameObject(const LoaderParams *pParams);
	virtual void Draw(SDL_Renderer *renderer);
	virtual void Update();
	virtual void Clean();
protected:
	std::string mTextureID;
	int mRow;
	int mColumn;
	Vector2D mSize;
	Vector2D mFramePosition;
	Vector2D mPosition;

};
