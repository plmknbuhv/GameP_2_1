#include "GameLogic.h"
#include "Console.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void Init()
{
	SetConsoleSettings(700, 700, false, TEXT("GampSnakeeeee"));
	SetCursorVisual(false, 50);
}