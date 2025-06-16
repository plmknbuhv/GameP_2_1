#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "TitleScene.h"

class SceneManager
{
public:
	SceneManager();
public:
	void RunScene();
	void ChangeScene(int sceneNum);
	void ChangeTitleScene(bool isTitle);
	void RenderTitleScene();
	void UpdateTitleScene();
private:
	void UpdateScene();
	void RenderScene();
private:
	int stageNum;
	bool isTitleScene;
	GameScene* currentGameScene;
	TitleScene* titleScene;
	POS resolution;
	static GameScene sceneList[10];
};

