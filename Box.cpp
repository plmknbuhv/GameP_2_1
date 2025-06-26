#include "Box.h"
#include "Console.h"

Box::Box(POS pos)
	: position()
{
	position = pos;
}

void Box::Init()
{
}

void Box::Update()
{
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