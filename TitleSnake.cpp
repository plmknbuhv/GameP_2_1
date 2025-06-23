#include "TitleSnake.h"
#include "Snake.h"
#include "Enums.h"
#include "Console.h"
#include "ICommand.h"
#include "SceneManager.h"

TitleSnake::TitleSnake()
{
}

void TitleSnake::Render()
{
	Gotoxy((beforeBody.x * 2), beforeBody.y);
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

void TitleSnake::MoveSnake(Dir dir)
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

	beforeBody = location.back();
	location.push_front(location.front() + nextPos);

	location.pop_back();
}

void TitleSnake::Update()
{

}

void TitleSnake::RenderSnake(std::deque<POS> q)
{
	int cnt = 0;
	while (!q.empty())
	{
		
		Gotoxy((q.back().x * 2), q.back().y);
		if (isCanRender)
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
		else
			cout << " ";

		q.pop_back();
		cnt++;
	}

	SetColor();
}
