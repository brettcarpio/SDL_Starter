#pragma once

#include "Scene.h"

class MenuScene : public Scene {
public:
	virtual void Update();
	virtual void Render();

	virtual bool OnEnter();
	virtual bool OnExit();

	virtual std::string GetID() const;

private:
	static const std::string mID;
	static void mMenuToGame();
};