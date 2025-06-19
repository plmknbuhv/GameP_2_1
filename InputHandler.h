#pragma once
#include<vector>
#include "Enums.h"

class ICommand;
struct InputKey
{
	int vk;
	Input key;
	bool wasPressed;
};
class InputHandler
{
public:
	InputHandler();
public:
	ICommand* HandleInput();
	Input HandleTitleInput();
	std::vector<InputKey> m_vecKeys;
};

