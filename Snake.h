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
	Snake();
	Snake(Map* map);
public:
	void InitSnake(POS headPos);
	void SpawnSnake(POS tailPos, int bodyCount);
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void RenderSnake(std::deque<POS> q);
public:
	POS GetSnakeHead();
	virtual void MoveSnake(Dir dir);
	void Dead(POS deadPos);
	void AddSnakeBody();
	bool CheckCanMove(const POS& currentPos);
	void ApplyGravity();
	void Interact();
public:
	std::deque<POS> location;
protected:
	std::deque<POS> beforeLocation;
	POS beforeBody;
	InputHandler* inputHandler;
	Map* map;
public:
	POS deadPos;
	bool isDead;
	bool isClear;
};