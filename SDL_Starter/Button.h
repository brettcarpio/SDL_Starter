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
	Button(const LoaderParams *params);
	~Button();

private:
	void Draw();
	void Update();
	void Clean();
};