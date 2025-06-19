#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include <iostream>

Snake::Snake()
	: inputHandler(nullptr)
	, isCanRender(false)
	, isTitleSnake(false)
	, beforeBody()
{
	inputHandler = new InputHandler;
}

void Snake::InitSnake(POS headPos)
{
	while (!location.empty())
		location.pop_back();
	location.push_front(headPos);
}

void Snake::SpawnSnake(POS tailPos, int bodyCount)
{
	InitSnake(tailPos);

	for (int i = 0; i < bodyCount; i++)
	{
		MoveSnake(Dir::RIGHT);
		AddSnakeBody();
	}
}

void Snake::Init()
{
}

POS Snake::GetSnakeHead()
{
	return location.front();
}

void Snake::HandlePressedMove()
{
}

void Snake::MoveSnake(Dir dir)
{	// 움직이는건 여기서 하고 이동 가능 여부는 따로 판단
	beforeBody = location.back();

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
		return;
		break;
	}

	location.push_front(location.front() + nextPos);

	location.pop_back();
}

void Snake::AddSnakeBody()
{
	location.push_back(beforeBody);
}

void Snake::Update()
{
	if (isTitleSnake) return;

	ICommand* cmd = inputHandler->HandleInput();
	if (cmd != nullptr)
	{
		cmd->Execute(this);
		delete cmd;
	}
}

void Snake::Render()
{
	if (isTitleSnake)
		Gotoxy(beforeBody.x, beforeBody.y);
	else
		Gotoxy(beforeBody.x + 20, beforeBody.y + 20);
	cout << " ";
	RenderSnake(location);
}

void Snake::RenderSnake(std::deque<POS> q)
{
	// int num = 0;
	while (!q.empty())
	{
		if (isTitleSnake)
			Gotoxy(q.back().x, q.back().y);
		else
			Gotoxy(q.back().x + 20, q.back().y + 20);
		if (isCanRender)
		{
			//cout << num;
			//num++;
			if (q.size() == 1)
				cout << "●";
			else
				cout << "□";
		}
		else
			cout << " ";

		q.pop_back();
	}
}
