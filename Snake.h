#pragma once
#include <queue>
#include "GameLogic.h"
#include "Enums.h"
#include "Actor.h"
#include "InputHandler.h"

class Snake : public Actor
{
public:
	Snake();
public:
	void InitSnake(POS headPos);
	void SpawnSnake(POS tailPos, int bodyCount);
	void Init() override;
	void Update() override;
	void Render() override;
	void RenderSnake(std::queue<POS> q);
public:
	POS GetSnakeHead();
	void MoveSnake(Dir dir);
	void AddSnakeBody();
private:
	std::queue<POS> location;
	POS beforeBody;
	InputHandler* inputHandler;
public:
	bool isCanRender;
	bool isTitleSnake;
};