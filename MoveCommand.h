#pragma once
#include "ICommand.h"
#include "Enums.h"

class MoveCommand : public ICommand
{
public:
	MoveCommand(Dir _dir, bool isPressed);
	virtual void Execute(Actor* _actor) override;
private:
	Dir m_dir;
	bool isPressed;
};

