#include "SceneManager.h"
#include "Console.h"

GameScene* SceneManager::sceneList[] =
{
	new GameScene(1, 2), // Ʃ�丮�� ��������
	//new GameScene(2, 2),
	//new GameScene(3, 2),
	//new GameScene(4, 2),
	//new GameScene(5, 2),
	//new GameScene(6, 2), // ��� ��������
	//new GameScene(7, 2),
	//new GameScene(8, 2),
	//new GameScene(9, 2),
	//new GameScene(10, 2),
	//new GameScene(11, 2), // �ڽ� ��������
	//new GameScene(12, 2),
	//new GameScene(13, 2),
	//new GameScene(14, 2),
	//new GameScene(15, 2),
	//new GameScene(16, 2),
	//new GameScene(17, 2), // ������ ��������
};

SceneManager::SceneManager() : Single()
	, stageNum(0)
	, currentGameScene(nullptr)
	, titleScene(new TitleScene)
	, gameOverScene(new EndingScene)
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

		FrameSync(45);
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
	if (stageNum == sizeof(sceneList) / sizeof(sceneList[0]))
	{
		currentGameScene = gameOverScene;
		currentGameScene->InitScene();
	}
	else
	{
		currentGameScene = SceneManager::sceneList[stageNum];
		currentGameScene->InitScene();
	}
}

void SceneManager::UpdateScene()
{
	currentGameScene->Update();
}

void SceneManager::RenderScene()
{
	currentGameScene->Render();
}