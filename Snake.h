#pragma once
#include <queue>
#include "GameLogic.h"
#include "Enums.h"
#include "Actor.h"

class Snake : public Actor
{
public:
	void InitSnake(POS headPos);
	void Update() override;
	void Render() override;
public:
	POS GetSnakeHead();
	void MoveSnake(Dir dir);
	void AddSnakeBody();
private :
	std::queue<POS> location;
	POS beforeBody;
public:
	bool isCanRender;
};

void RenderSnake(std::queue<POS> q, bool isCanRender);