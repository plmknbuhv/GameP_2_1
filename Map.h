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
	bool CheckCanMove(const POS& nextPos);
	bool CheckCanGravity(const POS& nextPos);
	bool CheckCanClear(const POS& nextPos);
	bool CheckCanEat(const POS& nextPos);
private:
	char gameMap[13][23];
	POS tailPos;
	POS endPos;
	int stageNum;
};

