#include "InputHandler.h"
#include "MoveCommand.h"
#include <Windows.h>

InputHandler::InputHandler()
{
	m_vecKeys.push_back({ 'W', Input::UP });
	m_vecKeys.push_back({ 'S', Input::DOWN });
	m_vecKeys.push_back({ 'A', Input::LEFT });
	m_vecKeys.push_back({ 'D', Input::RIGHT });
	m_vecKeys.push_back({ VK_SPACE, Input::SPACE });
}

ICommand* InputHandler::HandleInput()
{
	for (auto& key : m_vecKeys)
	{
		bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isDown)
			return new MoveCommand((Dir)key.key);
	}
	return nullptr;
	Sleep(30);
}

Input InputHandler::HandleTitleInput()
{
	for (auto& key : m_vecKeys)
	{
		bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isDown)
			return key.key;
	}
	return Input::NONE;
	Sleep(30);
}
