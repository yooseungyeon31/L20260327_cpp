#include <iostream>
#include "Engine.h"
#include "World.h"


using namespace std;

int SDL_main(int argc, char* argv[])
{

	//Uint64 CurrentTime = SDL_GetTicks64(); //시간 받아오기

	//SDL_Log("%d", CurrentTime);

	//for (int i = 0; i < 1000000; i++)
	//{

	//}

	//Uint64 ElaspedTime = SDL_GetTicks64();
	//SDL_Log("%d", ElaspedTime - CurrentTime);

	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();

	delete GEngine;

	return 0;
}


