#pragma once
#include "Scene.h"
#include "GameObject.h"
#include <vector>
using std::vector;

class GameScene : public Scene
{
public:
	void InitScene() override;
	void Update() override;
	void Render() override;
private:
	vector<GameObject> ObjList;
};

