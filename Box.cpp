#include "Box.h"
#include "Console.h"
#include "Map.h"

Box::Box(POS pos, Map* map)
	:map(map)
{
	position = pos;
}

void Box::Init()
{
}

void Box::Update()
{
	ApplyGravity();
}

void Box::Render()
{
	Gotoxy((position.x * 2) + 20, position.y + 20);
	cout << "¢É";
}

void Box::Push(POS nextOffset)
{
	position = position + nextOffset;
}

void Box::ApplyGravity()
{
	if (map->CheckCanGravityBox(position - POS(0, 1)) == false) return;

	beforePos = position;

	Gotoxy((position.x * 2) + 20, position.y + 20);
	cout << " ";

	position = position - POS(0, 1);

	if (position.y >= 18) // ¹Ù´Ú±îÁö ¶³¾îÁ³´Ù¸é
	{
		Destroy();
		return;
	}
}

void Box::Destroy()
{
	Gotoxy((position.x * 2) + 20, position.y + 20);
	cout << " ";
	map->RemoveBox(this);
}