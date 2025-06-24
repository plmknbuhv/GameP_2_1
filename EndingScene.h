#pragma once
#include <vector>
#include "Scene.h"
#include "EndingSnake.h"

class EndingScene : public Scene
{
public:
	EndingScene();
public:
	void InitScene() override;
	void Update() override;
	void Render() override;
private:
	void MoveSnake();
private:
	std::vector<EndingSnake*> snakes;
	POS resolution;
};

