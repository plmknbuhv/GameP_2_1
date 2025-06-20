#pragma once
#include <deque>
#include "GameLogic.h"
#include "Enums.h"
#include "Actor.h"
#include "InputHandler.h"
#include "Map.h"

class Snake : public Actor
{
public:
	Snake(Map* map);
public:
	void InitSnake(POS headPos);
	void SpawnSnake(POS tailPos, int bodyCount);
	void Init() override;
	void Update() override;
	void Render() override;
	void RenderSnake(std::deque<POS> q);
public:
	POS GetSnakeHead();
	void MoveSnake(Dir dir);
	void AddSnakeBody();
	bool CheckCanMove(const POS& nextPos);
	void ApplyGravity();
private:
	std::deque<POS> location;
	POS beforeBody;
	InputHandler* inputHandler;
	Map* map;
public:
	bool isCanRender;
	bool isTitleSnake;
	bool isFirstMove;
};