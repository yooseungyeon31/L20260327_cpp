#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();

	delete GEngine;


	return 0;
} 

