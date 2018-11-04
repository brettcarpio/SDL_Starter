#include "SceneManager.h"

void SceneManager::PushScene(std::shared_ptr<Scene> scene) 
{
	mScenes.push_back(scene);
	mScenes.back()->OnEnter();
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> scene)
{
	if (!mScenes.empty())
	{
		if (mScenes.back()->GetID() == scene->GetID())
		{
			return;
		}

		if (mScenes.back()->OnExit())
		{
			mScenes.pop_back();
		}
	}

	mScenes.push_back(scene);
	mScenes.back()->OnEnter();
}

void SceneManager::PopScene()
{
	if (!mScenes.empty())
	{
		if (mScenes.back()->OnExit())
		{
			mScenes.pop_back();
		}
	}
}

void SceneManager::Update()
{
	if (!mScenes.empty())
	{
		mScenes.back()->Update();
	}
}

void SceneManager::Render()
{
	if (!mScenes.empty())
	{
		mScenes.back()->Render();
	}
}
