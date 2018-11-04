#include <iostream>
#include <string>

#include "Game.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game *Game::mInstance = 0;

Game::Game() : mRunning(false), mSceneMgr(nullptr), mRenderer(nullptr), mWindow(nullptr) 
{
}

Game::~Game() 
{
	mWindow = nullptr;
	mRenderer = nullptr;
	mSceneMgr = nullptr;
}

bool Game::Init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
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
	mSceneMgr->PushScene(std::make_shared<MenuScene>());

	TextureManager::Instance()->Load("../Assets/SampleAnim.png", "walk", mRenderer);
	TextureManager::Instance()->Load("../Assets/SampleButton.png", "button", mRenderer);

	std::cout << "Init success\n";
	mRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::Render()
{
	SDL_RenderClear(mRenderer); // clear the renderer to the draw color
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	mSceneMgr->Render();
	SDL_RenderPresent(mRenderer); // draw to the screen
}

void Game::Update()
{
	mSceneMgr->Update();
}

void Game::HandleEvents()
{
	InputHandler::Instance()->Update();
}

void Game::Clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}

SDL_Renderer *Game::GetRenderer() const
{
	return mRenderer;
}

SceneManager *Game::GetSceneMgr() const
{
	return mSceneMgr.get();
}

bool Game::Running() const
{
	return mRunning;
}

void Game::Quit()
{
	mRunning = false;
}
