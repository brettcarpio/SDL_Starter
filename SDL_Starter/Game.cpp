#include <iostream>
#include <string>

#include "Game.h"

Game::Game(){}
Game::~Game() {}

bool Game::Init(const char * title, int xpos, int ypos, int width, int height, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		mWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (mWindow != 0) // window init success
		{
			std::cout << "Window creation success\n";
			mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
			if (mRenderer != 0) // renderer init success
			{
				std::cout << "Renderer creation success\n";
				SDL_SetRenderDrawColor(mRenderer,
					255, 255, 255, 255);
			}
			else
			{
				std::cout << "Renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "Window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	mSceneMgr = std::make_unique<SceneManager>();
	mSceneMgr->PushScene(new MenuScene());
	mSceneMgr->PushScene(new GameScene());

	std::cout << "Init success\n";
	mRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::Render()
{
	SDL_RenderClear(mRenderer); // clear the renderer to the draw color
	mSceneMgr->Render(mRenderer);
	SDL_RenderPresent(mRenderer); // draw to the screen
}

void Game::Update()
{
	mSceneMgr->Update();
}

void Game::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::Clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}

bool Game::Running() const
{
	return mRunning;
}
