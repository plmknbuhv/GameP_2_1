#include "Console.h" // ����� ������ �߿��ϴ�.

void SetConsoleSettings(int width,
	int height,
	bool isFullScreen,
	const std::wstring& title)
{
	SetConsoleTitle(title.c_str());

	HWND hwnd = GetConsoleWindow();
	if (isFullScreen)
	{
		// ���� Ÿ��Ʋ �ٸ� �����ϰ�ʹٸ�
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);

		ShowWindow(hwnd, SW_MAXIMIZE);
	}
	else
	{
		// �ػ� ����
		MoveWindow(hwnd, 0, 0, width, height, true);
	}
}

void SetLockResize()
{
	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE); // ������ ������ ������
	style &= ~WS_SIZEBOX & ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

BOOL IsGotoxy(int x, int y) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // ����� ������ ������
	COORD Cur = { x * 2, y }; // ������ �̴ϼȶ�����
	return SetConsoleCursorPosition(handle, Cur);
}

void Gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // ����� ������ ������
	COORD Cur = { x, y }; // ������ �̴ϼȶ�����
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
	SetConsoleCursorInfo(handle, &info); // Ŀ���� ũ��� ���̱� ���θ� ����
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
	// �ܼ� �ڵ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ����ü �ʱ�ȭ
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// ���� ��Ʈ ���� Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = _size; // ��, ����
	cf.FontWeight = _weight; // FW~
	wcscpy_s(cf.FaceName, _fontname); // ��Ʈ�̸� ����
	// ��Ʈ ���� Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}