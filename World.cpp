#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"
#include <fstream>

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();

}

//로드하기
void UWorld::Load(std::string MapName)
{
	std::ifstream MapStream(MapName);

	int Y = 0;
	while (!MapStream.eof()) //파일 끝에 도달할 때까지 반복
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '*')
			{
				SpawnActor<AWall>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(X, Y);
			}
		}
		Y++;
	}
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}

}