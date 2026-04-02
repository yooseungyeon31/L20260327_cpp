#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 1; //¹Ù´Ú ´ÙÀ½ º®

	R = 255;
	G = 155;
	B = 0;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AWall::~AWall()
{
}
