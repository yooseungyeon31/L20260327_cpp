#include "MyGM.h"
#include "SDL.h"

AMyGM::AMyGM()
{
	Name = "MyGM";
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		SDL_Log("Game Over");
		bGameOver = true;
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplete = false;
	if (!bGameComplete)
	{
		SDL_Log("GameComplete");

		bGameComplete = true;
	}
}
