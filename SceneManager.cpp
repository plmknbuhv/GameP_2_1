#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"

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

void SceneManager::RunScene()
{
	ChangeScene(stageNum++);

	while (true)
	{
		UpdateScene();
		RenderScene();
	}
}

void SceneManager::ChangeScene(int sceneNum)
{
	currentScene = SceneManager::sceneList[sceneNum];
}

void SceneManager::UpdateScene()
{
	currentScene.Update();
}

void SceneManager::RenderScene()
{
	currentScene.Render();
}