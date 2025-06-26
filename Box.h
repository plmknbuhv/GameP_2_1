#pragma once
#include "Actor.h"
#include "GameLogic.h"

class Box : public Actor
{
public:
	Box(POS pos);
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
public:
	void Push(POS nextOffset);
	POS position;
};

