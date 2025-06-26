#pragma once
#include "Scene.h"
#include "Actor.h"
#include "Snake.h"
#include <vector>
using std::vector;

class GameScene : public Scene
{
public:
	GameScene(int stageNum, int snakeBodyCount);
public:
	void InitScene() override;
	void Update() override;
	void Render() override;
	void StartScene();
private:
	vector<Actor*> ObjList;
	Snake* snake;
public:
	Snake* GetSnake();
private:
	POS tailPos;
	int snakeBodyCount;
	int stageNum;
};

