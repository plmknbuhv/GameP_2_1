#include "GameScene.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Map.h"
#include "Console.h"

GameScene::GameScene(int stageNum, int snakeBodyCount)
	: snake(nullptr)
	, tailPos()
	, stageNum(stageNum)
	, snakeBodyCount()
{
	auto map = new Map(stageNum);
	snake = new Snake(map);
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
	snake->isDead = false;
	snake->SpawnSnake(tailPos, snakeBodyCount);

	Render();

	StartScene();
}

void GameScene::StartScene()
{
	Gotoxy(0, 73);
	for (int i = 73; i > -2; i-=1)
	{
		Gotoxy(0, i);
		Sleep(7);
	}
}

void GameScene::Update()
{
	for (Actor* a : ObjList)
		a->Update();
	if (snake->isDead)
	{
		snake->Render();
		Sleep(1000);
		InitScene();
	}
}

void GameScene::Render()
{
	for (Actor* a : ObjList)
		a->Render();

	Gotoxy(2,1);
	cout << stageNum << " 스테이지";
}