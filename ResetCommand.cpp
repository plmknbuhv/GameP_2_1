#include "ResetCommand.h"
#include "Snake.h"

ResetCommand::ResetCommand()
{
}

void ResetCommand::Execute(Actor* _actor)
{
	Snake* snake = dynamic_cast<Snake*>(_actor);
	if (snake != nullptr)
	{
		snake->Dead();
	}
}
