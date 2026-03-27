#include "Wall.h"
#include <iostream>

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 1; //바닥 다음 벽
}

AWall::~AWall()
{
}
