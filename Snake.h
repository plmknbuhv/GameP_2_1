#pragma once
#include <deque>
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
	void RenderSnake(std::deque<POS> q);
public:
	POS GetSnakeHead();
	void HandlePressedMove();
	void MoveSnake(Dir dir);
	void AddSnakeBody();
private:
	std::deque<POS> location;
	POS beforeBody;
	InputHandler* inputHandler;
public:
	bool isCanRender;
	bool isTitleSnake;
};