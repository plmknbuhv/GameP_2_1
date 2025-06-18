#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "Single.h"

class SceneManager : public Single
{
public:
	SceneManager();
public:
	void RunScene();
	void ChangeGameScene();
	void ChangeTitleScene();
	void ChangeNextStage();
private:
	void UpdateScene();
	void RenderScene();
private:
	int stageNum;
	Scene* currentGameScene;
	TitleScene* titleScene;
	POS resolution;
	static GameScene* sceneList[];
};

