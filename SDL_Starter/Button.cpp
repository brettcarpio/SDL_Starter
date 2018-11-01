#include "Button.h"
#include "InputHandler.h"

Button::Button(const LoaderParams *params, void(*callback)()) : GameObject(params), mReleased(true), mCallBack(callback), mClicked(false)
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
	if (mClicked)
	{
		mClicked = false;
		SDL_Delay(100);
		if (mCallBack != nullptr)
			mCallBack();
	}

	Vector2D* mousePos = InputHandler::Instance()->GetMousePosition();
	if (mousePos->x < mPosition.x + mSize.x &&
		mousePos->x > mPosition.x &&
		mousePos->y < mPosition.y + mSize.y &&
		mousePos->y > mPosition.y)
	{
		if (InputHandler::Instance()->GetMouseBtnState(MouseButtons::LEFT) && mReleased)
		{
			mColumn = CLICKED;
			mReleased = false;
		}
		else if (!InputHandler::Instance()->GetMouseBtnState(MouseButtons::LEFT))
		{
			mReleased = true;
			if (mColumn == CLICKED && mReleased)
			{
				mColumn = MOUSE_OUT;
				mClicked = true;
				return;
			}
		}
	}
	else 
	{
		mColumn = MOUSE_OUT;
	}
}

void Button::Clean()
{
}