#include "MoveCommand.h"
#include "Snake.h"

MoveCommand::MoveCommand(Dir _dir)
	: m_dir(_dir)
{
}

void MoveCommand::Execute(Actor* _actor)
{
	Snake* snake = dynamic_cast<Snake*>(_actor);
	if (snake != nullptr)
	{
		snake->MoveSnake(m_dir);
	}
}
