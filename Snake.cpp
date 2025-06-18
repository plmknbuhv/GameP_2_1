#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include <iostream>

Snake::Snake()
	: inputHandler(nullptr)
{
	inputHandler = new InputHandler;
}

void Snake::InitSnake(POS headPos)
{
	while (!location.empty())
		location.pop();
	location.push(headPos);
}

void Snake::SpawnSnake(POS tailPos, int bodyCount)
{
	InitSnake({ tailPos.x + 2, tailPos.y });

	for (int i = 0; i < 4; i++)
	{
		MoveSnake(Dir::LEFT);
		AddSnakeBody();
	}
}

void Snake::Init()
{
}

POS Snake::GetSnakeHead()
{
	return location.back();
}

void Snake::MoveSnake(Dir dir)
{	// 움직이는건 여기서 하고 이동 가능 여부는 따로 판단

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

	beforeBody = location.front();
	location.pop();
}

void Snake::AddSnakeBody()
{
	location.push(beforeBody);
	cout << beforeBody.x << beforeBody.y << "\n";
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
	Gotoxy(beforeBody.x, beforeBody.y);
	cout << " ";
	RenderSnake(location);
}

void Snake::RenderSnake(std::queue<POS> q)
{
	int num = 0;
	while (!q.empty())
	{
		Gotoxy(q.front().x, q.front().y);
		//if (isTitleSnake)
		//	Gotoxy(q.front().x, q.front().y);
		//else
		//	Gotoxy(q.front().x + 20, q.front().y + 20);
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

		q.pop();
	}
}
