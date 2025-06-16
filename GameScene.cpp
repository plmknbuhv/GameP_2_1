#include "GameScene.h"
#include "Map.h"

GameScene::GameScene(int stageNum)
{
	ObjList.push_back(Map(stageNum));
}

void GameScene::InitScene()
{
}

void GameScene::Update()
{
}

void GameScene::Render()
{
}
