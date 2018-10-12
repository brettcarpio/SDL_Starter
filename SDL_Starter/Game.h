#pragma once

#include "SDL.h"

class Game {
public:
	Game();
	~Game();

	bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void Render();
	void Update();
	void HandleEvents();
	void Clean();

	bool Running() const;
private:
	SDL_Window * mWindow;
	SDL_Renderer * mRenderer;
	bool mRunning;
};