#pragma once
#include <string>
//#include "SDL.h"

struct SDL_Surface;
struct SDL_Texture;

class AActor
{

public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();

	//오버라이드 재정의
	virtual void Tick();

	virtual void Render();

	void SetActorLocation(int NewX, int NewY);




	inline const int GetZOrder() //순서
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;

	int R;
	int G;
	int B;

	int ZOrder=0 ; //먼저 그리는 순서관련 변수
	char Mesh;

	SDL_Surface* Image;
	SDL_Texture* Texture; //텍스처로 이미지를 만든다. 
	//텍스처는 조작이 가능함.

};

