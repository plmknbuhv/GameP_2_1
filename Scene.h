#pragma once

class Scene
{
public:
	virtual void InitScene() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
};

