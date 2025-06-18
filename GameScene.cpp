#include "GameScene.h"
#include <iostream>
#include "Map.h"

GameScene::GameScene(int stageNum, int snakeBodyCount)
	: snake(nullptr)
	, tailPos()
	, snakeBodyCount()
{
	auto map = new Map(stageNum);
	snake = new Snake();
	snake->isCanRender = true;
    POS tail; map->GetTailPos(tail);
	tailPos = tail;
	this->snakeBodyCount = snakeBodyCount;
	
	ObjList.push_back(map);
	ObjList.push_back(snake);
}

void GameScene::InitScene()
{
	system("cls");
	for (Actor* a : ObjList)
		a->Init();
	snake->SpawnSnake(tailPos, snakeBodyCount);
}

void GameScene::Update()
{
	for (Actor* a : ObjList)
		a->Update();
}

void GameScene::Render()
{
	for (Actor* a : ObjList)
		a->Render();
}