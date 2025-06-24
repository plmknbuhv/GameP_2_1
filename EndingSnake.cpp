#include "EndingSnake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include "SceneManager.h"

EndingSnake::EndingSnake()
{
}

void EndingSnake::Render()
{
	if (!(beforeBody.x >= 8 &&
		beforeBody.x <= 34 &&
		beforeBody.y >= 10 &&
		beforeBody.y <= 15))
	{
		Gotoxy((beforeBody.x * 2), beforeBody.y);
		cout << " ";
	}

	while (!beforeLocation.empty())
		beforeLocation.pop_back();

	RenderSnake(location);
}

void EndingSnake::MoveSnake(Dir dir)
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

	beforeBody = location.back();
	nextPos = nextPos + location.front();

	if (nextPos.x > 40)
		nextPos.x = 0;
	if (nextPos.y > 40)
		nextPos.y = 0;
	if (nextPos.x < 0)
		nextPos.x = 40;
	if (nextPos.y < 0)
		nextPos.y = 40;

	location.push_front(nextPos);

	location.pop_back();
}

void EndingSnake::Init()
{
	InitSnake({rand() % 27 + 7, rand() % 27 + 7 });
	auto dir = (Dir)(rand() % 4);
	for (int i = 0; i < rand() % 5 + 2; i++)
	{
		MoveSnake(dir);
		AddSnakeBody();
	}
	moveCount = rand() % 10 + 5;
	moveDir = (Dir)(rand() % 4);
}

void EndingSnake::Update()
{
	if (moveCount <= 0)
	{
		moveCount = rand() % 10 + 2;
		moveDir = (Dir)(rand() % 4);
	}

	moveCount--;
	MoveSnake(moveDir);
}

void EndingSnake::RenderSnake(std::deque<POS> q)
{
	int cnt = 0;
	while (!q.empty())
	{
		Gotoxy((q.back().x * 2), q.back().y);

		if (!(q.back().x >= 8 &&
			q.back().x <= 34 &&
			q.back().y >= 10 &&
			q.back().y <= 15))
		{
			if (q.size() == 1)
			{
				SetColor();
				cout << "б▄";
			}
			else
			{
				if (cnt % 3 == 0)
					SetColor(COLOR::RED);
				else if (cnt % 3 == 1)
					SetColor(COLOR::YELLOW);
				else
					SetColor(COLOR::LIGHT_YELLOW);

				cout << "бр";
			}
		}

		q.pop_back();
		cnt++;
	}

	SetColor();
}
