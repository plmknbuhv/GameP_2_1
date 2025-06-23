#pragma once
#include "Snake.h"

class TitleSnake : public Snake
{
public:
	TitleSnake();
public:
	bool isCanRender;
public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void MoveSnake(Dir dir) override;
	virtual void RenderSnake(std::deque<POS> q) override;
};

