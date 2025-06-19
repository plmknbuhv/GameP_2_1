#include "MoveCommand.h"
#include "Snake.h"
#include "Console.h"
#include <iostream>

MoveCommand::MoveCommand(Dir _dir, bool isPressed)
	: m_dir(_dir)
	, isPressed(isPressed)
{
}

void MoveCommand::Execute(Actor* _actor)
{
	Snake* snake = dynamic_cast<Snake*>(_actor);
	if (snake != nullptr)
	{
		if (isPressed)
			snake->MoveSnake(m_dir);
		else
		{
			Gotoxy(0, 0);
			std::cout << isPressed;
		}
	}
}
