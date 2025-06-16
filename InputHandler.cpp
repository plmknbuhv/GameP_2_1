#include "InputHandler.h"
#include "MoveCommand.h"
#include <Windows.h>

InputHandler::InputHandler()
{
	m_vecKeys.push_back({ 'W', Dir::UP });
	m_vecKeys.push_back({ 'S', Dir::DOWN });
	m_vecKeys.push_back({ 'A', Dir::LEFT });
	m_vecKeys.push_back({ 'D', Dir::RIGHT });

	m_vecKeys.push_back({ VK_UP, Dir::UP });
}

ICommand* InputHandler::HandleInput()
{
	for (auto& key : m_vecKeys)
	{
		bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isDown)
			return new MoveCommand(key.dir);
	}
	Sleep(30);
	return nullptr;
}
