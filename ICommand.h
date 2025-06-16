#pragma once

class Actor;
class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Execute(Actor* _actor) abstract;
};


