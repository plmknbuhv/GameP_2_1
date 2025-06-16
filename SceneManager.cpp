#include "SceneManager.h"
#include "Console.h"

GameScene* SceneManager::sceneList[] =
{
	new GameScene(1),
}; // 딜리트 해야함

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
	Gotoxy(9, 9);
	cout << stageNum;
	//currentGameScene = sceneList[stageNum];
	//currentGameScene->InitScene();
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