#pragma once
#include <queue>
#include "GameLogic.h"
#include "GameObject.h"

class Snake : public GameObject
{
private :
	std::queue<POS> location;
};

