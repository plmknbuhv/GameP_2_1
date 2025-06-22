#pragma once
#include "Scene.h"
class OverScene : public Scene
{
public:
	OverScene();
public:
	void InitScene() override;
	void Update() override;
	void Render() override;
};

