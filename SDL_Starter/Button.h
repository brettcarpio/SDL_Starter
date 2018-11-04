#pragma once
#include "GameObject.h"

enum ButtonStates
{
	MOUSE_OUT = 0,
	CLICKED = 1
};

class Button : public GameObject
{
public:
	Button(const std::shared_ptr<LoaderParams> LoaderParams, void(*callback)());
	~Button();

private:
	void Draw();
	void Update();
	void Clean();

	void(*mCallBack)();
	bool mReleased;
	bool mClicked;
};