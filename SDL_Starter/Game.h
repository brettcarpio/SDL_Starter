#pragma once

#include <memory>

#include "SDL.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

class Game {
public:
	Game();
	~Game();

	bool Init(const char *title, int xpos, int ypos, int width, int height, int flags);

	void Render();
	void Update();
	void HandleEvents();
	void Clean();

	bool Running() const;
private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	std::unique_ptr<SceneManager> mSceneMgr;
	bool mRunning;
};