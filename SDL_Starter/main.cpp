#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;
	game.Init("Game", 100, 100, 640, 480, 0);

	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	game.Clean();
	return 0;
}