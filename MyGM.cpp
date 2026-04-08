#include "MyGM.h"
#include "SDL.h"
#include "Engine.h"
#include "World.h"
#include "YoudieActor.h"
#include "TextRenderActor.h"
#include "TextRenderComponent.h"

//tick을 재정의 해야 게임모드 틱을 안가져옴
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
		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
		if (TextActor)
		{
			TextActor->TextRenderComponent->bIsVisible = true;
		}

		SDL_Log("Game Over");
		bGameOver = true;
	}
}

//void AMyGM::GameComplete()
//{
//	static bool bGameComplete = false;
//
//	if (!bGameComplete)
//	{
//		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
//		if (TextActor)
//		{
//			TextActor->TextRenderComponent->bIsVisible = true;
//		}
//
//		SDL_Log("Game Complete");
//
//		bGameComplete = true;
//	}
//}
void AMyGM::GameComplete()
{
	static bool bGameComplete = false;

	if (!bGameComplete)
	{
		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
		if (TextActor)
		{
			// 컴포넌트의 텍스트를 "Mission Complete"로 변경
			TextActor->TextRenderComponent->SetText("You Win!");
			TextActor->TextRenderComponent->bIsVisible = true;
		}

		SDL_Log("Game Complete");
		bGameComplete = true;
	}
}