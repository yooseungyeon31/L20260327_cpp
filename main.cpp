#include <iostream>
#include "Engine.h"
#include "World.h"
#include "Component.h"
#include <map>



using namespace std;

class USpriteRenderComponent : UComponent
{
public:
	USpriteRenderComponent()
	{

	}
	virtual ~USpriteRenderComponent()
	{

	}

	virtual void Tick() override
	{

	}
	virtual void BeginPlay() override
	{

	}
};

class UCollisionComponent : UComponent
{
public:
	UCollisionComponent()
	{

	}
	virtual ~UCollisionComponent()
	{

	}



};


int SDL_main(int argc, char* argv[])
{

	//추상클래스는 바로 생성이 안됨
	//상속 받아서 구현함
	//자식에서 이 함수를 무조건 재정의 해야함.
	USpriteRenderComponent A;


	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();

	delete GEngine;

	return 0;
}


