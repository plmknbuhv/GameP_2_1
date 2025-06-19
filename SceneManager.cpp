#include "SceneManager.h"
#include "Console.h"

GameScene* SceneManager::sceneList[] =
{
	new GameScene(1, 3),
}; // µô¸®Æ® ÇØ¾ßÇÔ

SceneManager::SceneManager() : Single()
, stageNum(0)
, currentGameScene(nullptr)
, titleScene(new TitleScene)
, resolution{}
{
resolution = GetConsoleResolution();
}

void SceneManager::RunScene()
{
	ChangeTitleScene();

	while (true)
	{
		UpdateScene();
		RenderScene();

		FrameSync(60);
	}
}

void SceneManager::ChangeGameScene()
{
	currentGameScene = sceneList[stageNum];
	currentGameScene->InitScene();
} 

void SceneManager::ChangeTitleScene()
{
	currentGameScene = titleScene;
	titleScene->InitScene();
}

void SceneManager::ChangeNextStage()
{
	stageNum++;
	currentGameScene = SceneManager::sceneList[stageNum];
}

void SceneManager::UpdateScene()
{
	currentGameScene->Update();
}

void SceneManager::RenderScene()
{
	currentGameScene->Render();
}