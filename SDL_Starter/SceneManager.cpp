#include "SceneManager.h"

void SceneManager::PushScene(Scene* scene) 
{
	mScenes.push_back(scene);
	mScenes.back()->OnEnter();
}

void SceneManager::ChangeScene(Scene * scene)
{
	if (!mScenes.empty())
	{
		if (mScenes.back()->GetID() == scene->GetID())
		{
			return;
		}

		if (mScenes.back()->OnExit())
		{
			delete mScenes.back();
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
			delete mScenes.back();
			mScenes.pop_back();
		}
	}
}
