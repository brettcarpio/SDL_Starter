#pragma once

#include <memory>

#include "SDL.h"
#include "SceneManager.h"

class Game {
public:
	static Game *Instance()
	{
		if (mInstance == 0)
		{
			mInstance = new Game();
		}
		return mInstance;
	}

	bool Init(const char *title, int xpos, int ypos, int width, int height, int flags);

	void Render();
	void Update();
	void HandleEvents();
	void Clean();

	SDL_Renderer *GetRenderer() const;
	SceneManager *GetSceneMgr() const;
	bool Running() const;
	void Quit();
private:
	Game();
	~Game();

	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	std::unique_ptr<SceneManager> mSceneMgr;
	bool mRunning;
	static Game *mInstance;
};