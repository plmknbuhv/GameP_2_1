#pragma once
#include "Scene.h"

class SceneManager
{
public:
	void RunScene();
	void ChangeScene(int sceneNum);
private:
	void UpdateScene();
	void RenderScene();
private:
	int stageNum;
	GameScene currentScene;
	static GameScene sceneList[10];
};

