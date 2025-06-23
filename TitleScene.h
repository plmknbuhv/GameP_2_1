#pragma once
#include "Scene.h"
#include "Actor.h"
#include "TitleSnake.h"

class InputHandler;
class TitleScene : public Scene
{
public:
	TitleScene();
public :
	void InitScene() override;
	void Update() override;
	void Render() override;
private :
	TitleSnake* startSnake;
	TitleSnake* endSnake;
	int circleNum;
	POS startButtonPos;
	POS overButtonPos;
	POS resolution;
	Dir currentButton;
	InputHandler* inputHandler;
};