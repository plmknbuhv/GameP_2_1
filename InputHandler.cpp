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
		bool isPressed = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isPressed && !key.wasPressed)
		{
			key.wasPressed = isPressed;
			return new MoveCommand((Dir)key.key, true);
		}
		else if (!isPressed && key.wasPressed)
		{
			key.wasPressed = isPressed;
			return new MoveCommand((Dir)key.key, false);
		}
	}
	return nullptr;
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
}
