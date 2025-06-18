#pragma once
#include "Actor.h"
#include "GameLogic.h"

class Map : public Actor
{
public:
	Map(int stageNum);
public:
	void Init() override;
	void Update() override;
	void Render() override;
public:
	void GetTailPos(POS& tailPos);
private:
	char gameMap[10][16];
	POS tailPos;
	POS endPos;
};

