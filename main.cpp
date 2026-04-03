#include  <iostream>
#include "Engine.h"
#include "World.h"
#include "Component.h"

#include <vector>



int SDL_main(int argc, char* argv[])
{

	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();

	delete GEngine;

	return 0;
}