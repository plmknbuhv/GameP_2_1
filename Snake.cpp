#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include <iostream>

Snake::Snake(Map* map)
	: inputHandler(nullptr)
	, isCanRender(false)
	, isTitleSnake(false)
	, beforeBody()
	, map(map)
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

void Snake::MoveSnake(Dir dir)
{	
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
		nextPos = { -1, 0 };
		break;
	case Dir::RIGHT:
		nextPos = { 1, 0 };
		break;
	default:
		return;
		break;
	}

	if (map != nullptr && 
		(!map->CheckCanMove(location.front() + nextPos)
		|| !CheckCanMove(location.front() + nextPos)))
		return;

	isFirstMove = !isFirstMove;
	beforeBody = location.back();
	location.push_front(location.front() + nextPos);

	location.pop_back();
}

void Snake::AddSnakeBody()
{
	location.push_back(beforeBody);
}

bool Snake::CheckCanMove(const POS& nextPos)
{
	for (auto p : location)
	{
		if (p == nextPos)
			return false;
	}

	return true;
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

	ApplyGravity();
}

void Snake::ApplyGravity()
{
	bool isCanDrop = true;
	for (auto p : location)
	{
		if (CheckCanMove(p - POS(0, 1))
			isCanDrop = false;
	}
}

void Snake::Render()
{
	if (isTitleSnake)
		Gotoxy((beforeBody.x * 2), beforeBody.y);
	else
		Gotoxy((beforeBody.x * 2) + 20, beforeBody.y + 20);
	cout << " ";
	RenderSnake(location);
}

void Snake::RenderSnake(std::deque<POS> q)
{
	int cnt = isFirstMove ? 0 : 1;
	while (!q.empty())
	{
		if (isTitleSnake)
			Gotoxy((q.back().x * 2), q.back().y);
		else
			Gotoxy((q.back().x * 2) + 20, q.back().y + 20);
		if (isCanRender)
		{
			if (q.size() == 1)
				cout << "б▄";
			else
			{
				if (cnt % 2 == 0)
					cout << "бр";
				else
					cout << "бс";
			}
		}
		else
			cout << " ";

		q.pop_back();
		cnt++;
	}
}
