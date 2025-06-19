#include "MoveCommand.h"
#include "Snake.h"

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
	}
}
