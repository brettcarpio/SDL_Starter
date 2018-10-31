#include "Button.h"
#include "InputHandler.h"

Button::Button(const LoaderParams *params, void(*callback)()) : GameObject(params), mReleased(true), mCallBack(callback)
{
	mColumn = MOUSE_OUT;
}

Button::~Button()
{
}

void Button::Draw()
{
	GameObject::Draw();
}

void Button::Update()
{
	Vector2D* mousePos = InputHandler::Instance()->GetMousePosition();
	if (mousePos->x < mPosition.x + mSize.x &&
		mousePos->x > mPosition.x &&
		mousePos->y < mPosition.y + mSize.y &&
		mousePos->y > mPosition.y)
	{
		if (InputHandler::Instance()->GetMouseBtnState(0))
		{
			mColumn = CLICKED;
			if (mCallBack != nullptr)
				mCallBack();
		}
		else
		{
			mColumn = MOUSE_OUT;
		}
	}
}

void Button::Clean()
{
}