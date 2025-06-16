#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include <iostream>

void Snake::InitSnake(POS headPos)
{
	while (!location.empty())
		location.pop();
	location.push(headPos);
}

POS Snake::GetSnakeHead()
{
	return location.back();
}

void Snake::MoveSnake(Dir dir)
{	// 움직이는건 여기서 하고 이동 가능 여부는 따로 판단
	beforeBody = location.front();

	POS nextPos;
	switch (dir)
	{
	case Dir::UP:
		nextPos = { 0, -1 };
		break;
	case Dir::DOWN:
		nextPos = { 0, 1 };
		break;
	case Dir::LEFT:
		nextPos = { -2, 0 };
		break;
	case Dir::RIGHT:
		nextPos = { 2, 0 };
		break;
	default:
		nextPos = { 0, 0 };
		break;
	}

	location.push(location.back() + nextPos);

	location.pop();
}

void Snake::AddSnakeBody()
{
	location.push(beforeBody);
}

void Snake::Update()
{
}

void Snake::Render()
{
	Gotoxy(beforeBody.x, beforeBody.y);
	cout << " ";
	RenderSnake(location, isCanRender);
}

void RenderSnake(std::queue<POS> q, bool isCanRender)
{
	while (!q.empty())
	{
		Gotoxy(q.front().x, q.front().y);
		if (isCanRender)
		{
			if (q.size() == 1)
				cout << "□";
			else
				cout << "■";
		}
		else
			cout << " ";

		q.pop();
	}
}
