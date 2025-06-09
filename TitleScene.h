#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public :
	void InitScene() override;
	void Update() override;
	void Render() override;
};