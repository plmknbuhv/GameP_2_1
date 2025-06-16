#include "SceneManager.h"
#include "Console.h"

GameScene SceneManager::sceneList[] =
{
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
	GameScene(),
};

SceneManager::SceneManager() : Single()
, stageNum(0)
, isTitleScene(true)
, currentGameScene(nullptr)
, titleScene(new TitleScene)
, resolution{}
{
resolution = GetConsoleResolution();
}

void SceneManager::RunScene()
{
	ChangeTitleScene(true);

	while (true)
	{
		if (isTitleScene)
		{
			UpdateTitleScene();
			RenderTitleScene();
		}
		else
		{
			UpdateScene();
			RenderScene();
		}

		FrameSync(60);
	}
}

void SceneManager::ChangeScene(int sceneNum)
{
 	*currentGameScene = SceneManager::sceneList[sceneNum];
	currentGameScene->InitScene();
}

void SceneManager::ChangeTitleScene(bool isTitle)
{
	isTitleScene = isTitle;
	if (isTitle)
		titleScene->InitScene();
}

void SceneManager::UpdateTitleScene()
{
	titleScene->Update();
}

void SceneManager::RenderTitleScene()
{
	titleScene->Render();
}

void SceneManager::UpdateScene()
{
	currentGameScene->Update();
}

void SceneManager::RenderScene()
{
	currentGameScene->Render();
}