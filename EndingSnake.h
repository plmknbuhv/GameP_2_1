#pragma once
#include "Snake.h"

class EndingSnake : public Snake
{
public:
	EndingSnake();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void MoveSnake(Dir dir) override;
	virtual void RenderSnake(std::deque<POS> q) override;
private:
	int moveCount;
	Dir moveDir;
};