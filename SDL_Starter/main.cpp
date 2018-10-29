#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
	Game game;
	game.Init("Game", 100, 100, 640, 480, 0);

	Uint32 frameStart, frameTime;

	while (game.Running())
	{
		frameStart = SDL_GetTicks();

		game.HandleEvents();
		game.Update();
		game.Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	game.Clean();
	return 0;
}