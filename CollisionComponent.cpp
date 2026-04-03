#include "CollisionComponent.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"


UCollisionComponent::UCollisionComponent() : bIsGenerateHit(false), bIsGenerateOverlap(false)
{ 
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::BeginPlay()
{
}


void UCollisionComponent::Tick()
{
	//현재 월드에 존재하는 모든 엑터들을 하나씩 꺼내서 나와 비교함
	for (auto Other : GEngine->GetWorld()->GetActors())
	{
		//자기 자신과는 충돌검사를 하지 않도록
		if (Other == this->Owner)
		{
			continue;
		}

		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateHit &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					Other->ReceiveHit(Owner);
					Owner->ReceiveHit(Other);
				}

				if (OtherCollision->bIsGenerateOverlap &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					if (Owner->OnActorBeginOverlap)
					{
						Owner->OnActorBeginOverlap(Other);
					}
					if (Other->OnActorBeginOverlap)
					{
						Other->OnActorBeginOverlap(Owner);
					}
				}
			}
		}
	}
}
