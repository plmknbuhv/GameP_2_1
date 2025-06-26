#pragma once
#include <vector>
#include "Actor.h"
#include "GameLogic.h"
#include "Box.h"

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
	bool PushBox(const POS& currentPos, const POS& nextOffset);
	bool CheckCanEat(const POS& nextPos);
private:
	char gameMap[13][23];
	POS tailPos;
	POS endPos;
	int stageNum;
	std::vector<Box*> boxes;
};

