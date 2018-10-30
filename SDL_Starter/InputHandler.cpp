#include "InputHandler.h"
#include "Game.h"

InputHandler *InputHandler::mInstance = 0;

InputHandler::InputHandler()
{
	for (int i = 0; i < 3; i++)
		mMouseBtnStates.push_back(false);
}

InputHandler::~InputHandler()
{
}

void InputHandler::OnMouseBtnDown(SDL_Event &e)
{
	if (e.button.button == SDL_BUTTON_LEFT)
	{
		mMouseBtnStates[LEFT] = true;
	}
	if (e.button.button == SDL_BUTTON_MIDDLE)
	{
		mMouseBtnStates[MIDDLE] = true;
	}
	if (e.button.button == SDL_BUTTON_RIGHT)
	{
		mMouseBtnStates[RIGHT] = true;
	}
}

void InputHandler::OnMouseBtnUp(SDL_Event &e)
{
	if (e.button.button == SDL_BUTTON_LEFT)
	{
		mMouseBtnStates[LEFT] = false;
	}
	if (e.button.button == SDL_BUTTON_MIDDLE)
	{
		mMouseBtnStates[MIDDLE] = false;
	}
	if (e.button.button == SDL_BUTTON_RIGHT)
	{
		mMouseBtnStates[RIGHT] = false;
	}
}

void InputHandler::OnKeyDown()
{
	mKeyStates = SDL_GetKeyboardState(0);
}

void InputHandler::OnKeyUp()
{
	mKeyStates = SDL_GetKeyboardState(0);
}

void InputHandler::Update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Game::Instance()->Quit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			OnMouseBtnDown(e);
			break;
		case SDL_MOUSEBUTTONUP:
			OnMouseBtnUp(e);
			break;
		case SDL_KEYDOWN:
			OnKeyDown();
		case SDL_KEYUP:
			OnKeyUp();
		default:
			break;
		}
	}
}

void InputHandler::Clean()
{
}

bool InputHandler::GetMouseBtnState(int btnNumber)
{
	return mMouseBtnStates[btnNumber];
}

bool InputHandler::IsKeyDown(SDL_Scancode key)
{
	if (mKeyStates != 0)
	{
		if (mKeyStates[key] == 1)
			return true;
		else
			return false;
	}
	return false;
}