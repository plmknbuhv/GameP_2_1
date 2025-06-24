#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "EndingScene.h"
#include "Console.h"

EndingScene::EndingScene()
	: snakes()
	, resolution()
{
	resolution = GetConsoleResolution();
}

void EndingScene::InitScene()
{
	system("cls");

	srand((unsigned int)time(NULL)); // 시드 값을 바꾸는 난수
	for (int i = 0; i < 6; i++)
	{
		EndingSnake *snake = new EndingSnake();
		snake->Init();
		snakes.push_back(snake);
	}
}

void EndingScene::Update()
{
	for (EndingSnake* a : snakes)
		a->Update();
	Sleep(10);
}

void EndingScene::Render()
{
	int y = resolution.y / 4;
	Gotoxy(0, y);

	int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"		 ██████╗██╗     ███████╗ █████╗ ██████╗   ██╗ ██╗ ██╗" << endl;
	wcout << L"		██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗  ██║ ██║ ██║" << endl;
	wcout << L"		██║     ██║     █████╗  ███████║██████╔╝  ██║ ██║ ██║" << endl;
	wcout << L"		██║     ██║     ██╔══╝  ██╔══██║██╔══██╗  ╚═╝ ╚═╝ ╚═╝" << endl;
	wcout << L"		╚██████╗███████╗███████╗██║  ██║██║  ██║  ██╗ ██╗ ██╗" << endl;
	wcout << L"		╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝ ╚═╝ ╚═╝";
	int wcoutMode = _setmode(_fileno(stdout), coutMode);

	for (EndingSnake* a : snakes)
		a->Render();


}