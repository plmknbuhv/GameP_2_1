#include "Console.h" // 헤더의 순서는 중요하다.

void SetConsoleSettings(int width,
	int height,
	bool isFullScreen,
	const std::wstring& title)
{
	SetConsoleTitle(title.c_str());

	HWND hwnd = GetConsoleWindow();
	if (isFullScreen)
	{
		// 위에 타이틀 바를 제거하고싶다면
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);

		ShowWindow(hwnd, SW_MAXIMIZE);
	}
	else
	{
		// 해상도 설정
		MoveWindow(hwnd, 0, 0, width, height, true);
	}
}

void SetLockResize()
{
	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE); // 윈도우 권한을 가져와
	style &= ~WS_SIZEBOX & ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

BOOL IsGotoxy(int x, int y) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 출력의 권한을 가져와
	COORD Cur = { x * 2, y }; // 유니폼 이니셜라이저
	return SetConsoleCursorPosition(handle, Cur);
}

void Gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 출력의 권한을 가져와
	COORD Cur = { x, y }; // 유니폼 이니셜라이저
	SetConsoleCursorPosition(handle, Cur);
}

COORD GetCursorPos()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(handle, &buf);
	return buf.dwCursorPosition;
}

void SetCursorVisual(bool isVis, DWORD size)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = { size, isVis };
	SetConsoleCursorInfo(handle, &info); // 커서의 크기와 보이기 여부를 결정
}

void SetColor(COLOR _textcolor, COLOR _bgcolor)
{
	int textcolor = (int)_textcolor;
	int bgcolor = (int)_bgcolor;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 
		(bgcolor << 4) | textcolor);
}

COORD GetConsoleResolution()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(handle, &buf);
	short width  = buf.srWindow.Right - buf.srWindow.Left + 1;
	short height = buf.srWindow.Bottom - buf.srWindow.Top + 1;
	return {width , height};
}

void FrameSync(unsigned int _frame)
{
	clock_t oldTime, curTime;
	oldTime = clock();
	while (true)
	{
		curTime = clock();
		if (curTime - oldTime >= 1000 / _frame)
		{
			oldTime = curTime;
			break;
		}
	}
}

void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight)
{
	// 콘솔 핸들
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 구조체 초기화
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// 현재 폰트 정보 Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = _size; // 폭, 높이
	cf.FontWeight = _weight; // FW~
	wcscpy_s(cf.FaceName, _fontname); // 폰트이름 복사
	// 폰트 정보 Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}