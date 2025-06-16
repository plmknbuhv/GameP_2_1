#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(int stageNum)
{
	std::ifstream mapFile(
		"stage{}.txt", stageNum);
	if (mapFile.is_open())
	{
		for (int i = 0; i < 32; i++)
		{
			mapFile >> gameMap[i];
		}
		mapFile.close();
		return;
	}
	else
	{
		std::cout << "¸Ê ¿¡¹Ýµù" << std::endl;
	}
}
