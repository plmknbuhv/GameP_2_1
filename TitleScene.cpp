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
	, inputHandler(nullptr)
	, circleNum()
	, startButtonPos()
	, overButtonPos()
	, currentButton()
	, resolution()
{
	circleNum = 0;

	resolution = GetConsoleResolution();
	int y = resolution.y / 3 * 2;
	int x = resolution.x / 4;
	startButtonPos = { x, y };
	overButtonPos = { x + 40, y };
	currentButton = Dir::LEFT;

	inputHandler = new InputHandler;
	startSnake = new Snake(); // 둘 다 딜리트 해줘야 함
	endSnake = new Snake();
}

void TitleScene::InitScene()
{
	startSnake->InitSnake({ startButtonPos.x+2, startButtonPos.y});
	startSnake->isCanRender = true;
	endSnake->InitSnake({ overButtonPos.x+2, overButtonPos.y});

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
	Input dir = inputHandler->HandleTitleInput();
	if (dir == Input::SPACE)
	{
		Gotoxy(9, 9);
		cout << (int)currentButton;
		if (currentButton == Dir::RIGHT)
		{
			exit(0);
		}
		else if (currentButton == Dir::LEFT)
		{
			Single* single = SceneManager::GetInst();
			SceneManager* manager = dynamic_cast<SceneManager*>(single);
			manager->ChangeScene(1);
		}
	}
	else if (dir != Input::NONE)
		currentButton = (Dir)dir;
	
	startSnake->MoveSnake(circleOffset[circleNum]);
	endSnake->MoveSnake(circleOffset[circleNum]);
	circleNum++;
	if (circleNum >= 14)
		circleNum = 0;
}

void TitleScene::Render()
{
	// 타이틀 그리기
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

	// 버튼 그리기
	Gotoxy(startButtonPos);
	cout << "게임시작";
	Gotoxy(overButtonPos);
	cout << "게임종료";

	// 뱀 그리기
	switch (currentButton)
	{
	case Dir::LEFT:
		startSnake->isCanRender = true;
		endSnake->isCanRender = false;
		break;
	case Dir::RIGHT:
		startSnake->isCanRender = false;
		endSnake->isCanRender = true;
		break;
	case Dir::NONE:
		break;
	}
	startSnake->Render();
	endSnake->Render();
}