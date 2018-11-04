#pragma once
#include <vector>
#include <memory>
#include "SDL.h"
#include "Vector2D.h"

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
		if (mInstance == nullptr)
		{
			mInstance = new InputHandler();
		}
		return mInstance;
	}
	static void DeleteInstance()
	{
		if (mInstance != nullptr)
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}
	void Update();
	void Clean();
	Vector2D *GetMousePosition() const;
	bool GetMouseBtnState(int btnNumber) const;
	bool IsKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler();

	void OnMouseMove(SDL_Event &e);
	void OnMouseBtnDown(SDL_Event &e);
	void OnMouseBtnUp(SDL_Event &e);
	void OnKeyDown();
	void OnKeyUp();

	static InputHandler *mInstance;
	std::vector<bool> mMouseBtnStates;
	const Uint8 *mKeyStates;
	std::shared_ptr<Vector2D> mMousePosition;
};