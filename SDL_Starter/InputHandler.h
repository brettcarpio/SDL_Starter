#pragma once
#include <vector>
#include "SDL.h"

enum MouseButtons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler 
{
public:
	static InputHandler *Instance()
	{
		if (mInstance == 0)
		{
			mInstance = new InputHandler();
		}
		return mInstance;
	}
	void Update();
	void Clean();
	bool GetMouseBtnState(int btnNumber);
	bool IsKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler();

	void OnMouseBtnDown(SDL_Event &e);
	void OnMouseBtnUp(SDL_Event &e);
	void OnKeyDown();
	void OnKeyUp();

	static InputHandler *mInstance;
	std::vector<bool> mMouseBtnStates;
	const Uint8 *mKeyStates;
};