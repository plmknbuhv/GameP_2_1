#include "Map.h"
#include "Console.h"
#include <fstream>
#include <format>
#include "Snake.h"
#include <iostream>

Map::Map(int stageNum) 
	: gameMap{}
	, tailPos{}
	, endPos{}
{
	// ¸Ê ºÒ·¯¿À±â
	std::string filename = std::format("Maps/Stage{}.txt", stageNum);
	std::ifstream mapFile(filename);
	if (mapFile.is_open())
	{
		for (int i = 0; i < 13; i++)
			mapFile >> gameMap[i];
		mapFile.close();
	}
	else
		std::cout << "¸Ê ¿¡¹Ýµù" << std::endl;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (gameMap[i][j] == '3')
				endPos = {j, i};
			else if (gameMap[i][j] == '2')
				tailPos = {j, i};
		}
	}
}

void Map::Init()
{

}

void Map::Update()
{

}

void Map::Render()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			Gotoxy((j*2) + 20, i + 20);
			if (gameMap[i][j] == '1')
				cout << "¡á";
			else if (gameMap[i][j] == '3')
				cout << "¢Í";
		}
	}
}

void Map::GetTailPos(POS& tailPos)
{
	tailPos = this->tailPos;
}

bool Map::CheckCanMove(const POS& nextPos)
{
	return (gameMap[nextPos.y][nextPos.x] != '1');
}

bool Map::CheckCanGravity(const POS& nextPos)
{
	return (gameMap[nextPos.y][nextPos.x] != '3'
		&& gameMap[nextPos.y][nextPos.x] != '1');
}

bool Map::CheckCanClear(const POS& nextPos)
{
	return(gameMap[nextPos.y][nextPos.x] == '3');
}