#pragma once
#include "Actor.h"

class Map : public Actor
{
public:
	Map(int stageNum);
private:
	char gameMap[16][32];
};

