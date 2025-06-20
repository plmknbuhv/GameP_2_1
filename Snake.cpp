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

	ApplyGravity();

	ICommand* cmd = inputHandler->HandleInput();
	if (cmd != nullptr)
	{
		cmd->Execute(this);
		delete cmd;
	}
}

void Snake::ApplyGravity()
{
	bool isCanDrop = true;
	while(isCanDrop == true)
	{
		isCanDrop = true;

		for (auto p : location)
		{
			if (map->CheckCanMove(p - POS(0, 1)) == false) // �ؿ� ������ ���ٸ�
			{
				isCanDrop = false;
				break;
			}
		}

		if (isCanDrop == false) return;

		for (auto& p : location)
		{
			beforeLocation.push_back(p);
			p = p - POS(0, 1);
		}

		beforeBody = { 0,0 };
	}
}

void Snake::Render()
{
	if (isTitleSnake)
		Gotoxy((beforeBody.x * 2), beforeBody.y);
	else
		Gotoxy((beforeBody.x * 2) + 20, beforeBody.y + 20);
	cout << " ";

	for (auto p : beforeLocation)
	{
		Gotoxy((p.x * 2) + 20, p.y + 20);
		cout << " ";
	}
	while (!beforeLocation.empty())
		beforeLocation.pop_back();

	RenderSnake(location);
}

void Snake::RenderSnake(std::deque<POS> q)
{
	int cnt = 0;
	while (!q.empty())
	{
		if (isTitleSnake)
			Gotoxy((q.back().x * 2), q.back().y);
		else
			Gotoxy((q.back().x * 2) + 20, q.back().y + 20);
		if (isCanRender)
		{
			if (q.size() == 1)
			{
				SetColor();
				cout << "��";
			}
			else
			{
				if (cnt % 3 == 0)
					SetColor(COLOR::RED);
				else if (cnt % 3 == 1)
					SetColor(COLOR::YELLOW);
				else
					SetColor(COLOR::LIGHT_YELLOW);

				cout << "��";
			}
		}
		else
			cout << " ";

		q.pop_back();
		cnt++;
	}

	SetColor();
}
