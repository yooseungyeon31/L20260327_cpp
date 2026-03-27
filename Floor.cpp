#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
}

AFloor::~AFloor()
{
}

void AFloor::Render() {
	// 아무것도 하지 않음 (임시 테스트)
}
