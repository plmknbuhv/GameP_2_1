#include <io.h>
#include <fcntl.h>
#include <iostream>
#include "Console.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Enums.h"
#include "InputHandler.h"
#include "ICommand.h"

Dir circleOffset[14] =
{
	Dir::UP, Dir::UP, Dir::RIGHT, Dir::RIGHT, Dir::RIGHT, Dir::RIGHT, Dir::RIGHT,
	Dir::DOWN, Dir::DOWN, Dir::LEFT, Dir::LEFT, Dir::LEFT, Dir::LEFT, Dir::LEFT,
};

TitleScene::TitleScene()
	: startSnake(nullptr)
	, endSnake(nullptr)
	, circleNum()
	, inputHandler()
	, startButtonPos()
	, overButtonPos()
	, resolution()
{
	circleNum = 0;

	resolution = GetConsoleResolution();
	int y = resolution.y / 3 * 2;
	int x = resolution.x / 4;
	startButtonPos = { x, y };
	overButtonPos = { x + 40, y };
}

void TitleScene::InitScene()
{
	startSnake->InitSnake({ startButtonPos.x+2, startButtonPos.y});
	endSnake->InitSnake({ startButtonPos.x+2, startButtonPos.y});

	for (int i = 0; i < 4; i++)
	{
		startSnake->MoveSnake(circleOffset[circleNum]);
		startSnake->AddSnakeBody();
		endSnake->MoveSnake(circleOffset[circleNum]);
		endSnake->AddSnakeBody();
		circleNum++;
	}
}

void TitleScene::Update()
{
	ICommand* cmd = m_inputHandler->HandleInput();
	if (cmd != nullptr)
	{
		cmd->Execute(m_player);
		delete cmd;
	}

	startSnake->MoveSnake(circleOffset[circleNum]);
	endSnake->MoveSnake(circleOffset[circleNum]);
	circleNum++;
	if (circleNum >= 14)
		circleNum = 0;
}

void TitleScene::Render()
{
	int y = resolution.y / 3;
	Gotoxy(0, y);
	int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"                  ███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗███████╗███████╗███████╗" << endl;
	wcout << L"                  ██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██╔════╝██╔════╝" << endl;
	wcout << L"                  ███████╗██╔██╗ ██║███████║█████╔╝ █████╗  █████╗  █████╗  █████╗  " << endl;
	wcout << L"                  ╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██╔══╝  ██╔══╝  " << endl;
	wcout << L"                  ███████║██║ ╚████║██║  ██║██║  ██╗███████╗███████╗███████╗███████╗" << endl;
	wcout << L"                  ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚══════╝" << endl;

	int wcoutMode = _setmode(_fileno(stdout), coutMode);

	Gotoxy(startButtonPos);
	cout << "게임시작";
	Gotoxy(overButtonPos);
	cout << "게임종료";

	snake.Render();
}