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
	, stageNum(stageNum)
{
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
	boxes.clear();
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
				endPos = { j, i };
			else if (gameMap[i][j] == '2')
				tailPos = { j, i };
			else if (gameMap[i][j] == '5')
			{
				Box* box = new Box(POS{j,i}, this); 
				boxes.push_back(box);
				gameMap[i][j] = '0';
			}
		}
	}
}

void Map::Update()
{
	for (auto b : boxes)
	{
		b->Update();
	}
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
			else if (gameMap[i][j] == '4')
				cout << "¢À";
		}
	}

	for (auto b : boxes)
	{
		b->Render();
	}
}

void Map::GetTailPos(POS& tailPos)
{
	tailPos = this->tailPos;
}

bool Map::CheckCanMove(const POS& nextPos)
{
	if (gameMap[nextPos.y][nextPos.x] == '1')
	{
		return false;
	}
}

bool Map::PushBox(const POS& currentPos, const POS& nextOffset)
{
	for (auto b : boxes)
	{
		if (b->position == currentPos)
		{
			auto nextPos = currentPos + nextOffset;
			if (gameMap[nextPos.y][nextPos.x] == '0')
			{
				b->Push(nextOffset);

				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

bool Map::CheckCanGravity(const POS& nextPos)
{
	for (auto b : boxes)
	{
		if (b->position == nextPos)
			return false;
	}
	return (gameMap[nextPos.y][nextPos.x] != '3' 
		&& gameMap[nextPos.y][nextPos.x] != '1'  
		&& gameMap[nextPos.y][nextPos.x] != '4');
}

bool Map::CheckCanClear(const POS& nextPos)
{
	return(gameMap[nextPos.y][nextPos.x] == '3');
}

bool Map::CheckCanEat(const POS& nextPos)
{
	if (gameMap[nextPos.y][nextPos.x] == '4')
	{
		gameMap[nextPos.y][nextPos.x] = '0';
		return true;
	}
	return false;
}

void Map::RemoveBox(Box* box)
{
	boxes.erase(std::remove(boxes.begin(), boxes.end(), box), boxes.end());
}	