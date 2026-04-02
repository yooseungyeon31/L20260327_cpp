#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 0; //바닥이 젤 먼저 깔려야 하니까 0으로 설정

	R = 0;
	G = 0;
	B = 0;

	Load("Data/floor.bmp");
}

AFloor::~AFloor()
{
}

