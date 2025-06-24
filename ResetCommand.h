#pragma once
#include "ICommand.h"

class ResetCommand : public ICommand
{
public:
	ResetCommand();
	virtual void Execute(Actor* _actor) override;
};

