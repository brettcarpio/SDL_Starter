#include "TextureManager.h"

TextureManager * TextureManager::mInstance = 0;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::Load(std::string filePath, std::string id, SDL_Renderer * renderer)
{
	SDL_Surface* tempSurface = IMG_Load(filePath.c_str());

	if (tempSurface == 0)
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_FreeSurface(tempSurface);

	if (texture != 0)
	{
		mTextureMap[id] = texture;
		return true;
	}

	return false;
}

void TextureManager::Draw(std::string id, Vector2D position, Vector2D size, SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = size.getX();
	srcRect.h = destRect.h = size.getY();
	destRect.x = position.getX();
	destRect.y = position.getY();

	SDL_RenderCopyEx(renderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, Vector2D position, Vector2D size, int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = size.getX() * currentFrame;
	srcRect.y = size.getY() * (currentRow - 1);
	srcRect.w = destRect.w = size.getX();
	srcRect.h = destRect.h = size.getY();
	destRect.x = position.getX();
	destRect.y = position.getY();

	SDL_RenderCopyEx(renderer, mTextureMap[id], &srcRect, &destRect, 0, 0, flip);
}
