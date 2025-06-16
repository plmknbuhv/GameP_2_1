#pragma once
#include "Scene.h"
#include "Actor.h"
#include "Snake.h"

class TitleScene : public Scene
{
	TitleScene() {};
public :
	void InitScene() override;
	void Update() override;
	void Render() override;
private :
	Snake* startSnake;
	Snake* endSnake;
	int circleNum;
	POS startButtonPos;
	POS overButtonPos;
	POS resolution;
	InputHandler inputHandler;
};