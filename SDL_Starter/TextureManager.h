#pragma once

#include <string>
#include <map>

#include "SDL_image.h"

class TextureManager {
public:
	static TextureManager* GetInstance()
	{
		if (mInstance == 0)
		{
			mInstance = new TextureManager();
			return mInstance;
		}

		return mInstance;
	}

	bool Load(std::string filePath, std::string id, SDL_Renderer * renderer);

	void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager();
	~TextureManager();
	static TextureManager * mInstance;
	std::map<std::string, SDL_Texture*> mTextureMap;
};