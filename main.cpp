#include <iostream>
#include <queue>
#include <vector>
#include "SceneManager.h"
#include "GameLogic.h"
#include "Mci.h"

int main()
{
	Init();
	SceneManager sceneManager;
	sceneManager.RunScene();
	ReleaseAllSounds();
}