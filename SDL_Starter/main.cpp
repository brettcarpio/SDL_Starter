#include <iostream>
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;

	if (Game::Instance()->Init("Game", 100, 100, 640, 480, 0))
	{
		while (Game::Instance()->Running())
		{
			frameStart = SDL_GetTicks();

			Game::Instance()->HandleEvents();
			Game::Instance()->Update();
			Game::Instance()->Render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	Game::Instance()->Clean();
	return 0;
}