#pragma once
#include "Actor.h"
#include "GameLogic.h"

class Map;
class Box : public Actor
{
public:
	Box(POS pos, Map* map);
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
public:
	void ApplyGravity();
	void Push(POS nextOffset);
	void Destroy();
public:
	POS position;
private:
	Map* map;
	POS beforePos;
};

