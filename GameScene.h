#pragma once
#include "Scene.h"
#include "Actor.h"
#include <vector>
using std::vector;

class GameScene : public Scene
{
public:
	GameScene(int stageNum);
public:
	void InitScene() override;
	void Update() override;
	void Render() override;
private:
	vector<Actor> ObjList;
};

