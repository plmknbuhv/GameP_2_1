#pragma once
#include <iostream>
#include "GameLogic.h" // 헤더의 순서는 중요하다.
using std::cout;
using std::cin;
using std::wcout;
using std::endl;

#include <string>
using std::string;
using std::wstring;

#include <Windows.h>"

void SetConsoleSettings(int width,
	int height,
	bool isFullScreen,
	const std::wstring& title);
void SetLockResize();
void Gotoxy(int x, int y);
void Gotoxy(POS pos);
BOOL IsGotoxy(int x, int y);
void HideCursor();

COORD GetCursorPos();
void SetCursorVisual(bool isVis, DWORD size);
enum class COLOR
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE, END
};
void SetColor(COLOR textcolor = COLOR::WHITE, COLOR bgcolor = COLOR::BLACK);
POS GetConsoleResolution();
void FrameSync(unsigned int _frame);
void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight);