#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include "SceneManager.h"
#include <iostream>

Snake::Snake(Map* map)
	: inputHandler(nullptr)
	, isCanRender(false)
	, isTitleSnake(false)
	, beforeBody{ 0, -3 }
	, isDead(false)
	, isClear(false)
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
	if (isDead) return;

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

	if (isTitleSnake == false)
		Interact();
}

void Snake::Interact()
{
	if (!map->CheckCanClear(location.front()))
		return;

	isClear = true;
	while (!location.empty())
	{
		Render();
		beforeBody = location.back();
		location.pop_back();
		Sleep(75);
	}

	Sleep(1000);
	Single* single = SceneManager::GetInst();
	SceneManager* manager = dynamic_cast<SceneManager*>(single);
	manager->ChangeNextStage();
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
	if (isDead) return;

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
			if (map->CheckCanGravity(p - POS(0, 1)) == false) // 밑에 공간이 없다면
			{
				isCanDrop = false;
				break;
			}
		}

		if (isCanDrop == false) return;
		Sleep(30);
		Render();

		for (auto& p : location)
		{
			beforeLocation.push_back(p);
			p = p - POS(0, 1);
		}

		beforeBody = { 0, -3 };

		if (location.front().y >= 20) // 바닥까지 떨어졌다면
		{
			Dead();
			return;
		}
	}
}

void Snake::Dead()
{
	isDead = true;
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
				if (isClear == false)
					cout << "●";
				else
					cout << "♨";
			}
			else
			{
				if (cnt % 3 == 0)
					SetColor(COLOR::RED);
				else if (cnt % 3 == 1)
					SetColor(COLOR::YELLOW);
				else
					SetColor(COLOR::LIGHT_YELLOW);

				cout << "□";
			}
		}
		else
			cout << " ";

		q.pop_back();
		cnt++;
	}

	SetColor();
}
