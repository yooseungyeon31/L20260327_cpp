#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>

using namespace std;

class Singleton
{
private:
	Singleton()
	{

	}

	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}
		return Instance;
	}
};

Singleton* Singleton::Instance = nullptr;

int main()
{


	//UEngine* MyEngine = new UEngine();
	//MyEngine->GetWorld()->Load("level01.umap");

	//MyEngine->Run();

	//delete MyEngine;

	GEngine->GetInstance();

	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();


	return 0;
}