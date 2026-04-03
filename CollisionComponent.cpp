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
	for (auto Other : Owner->GetWorld()->GetActors())
	{
		//자기 자신과는 충돌검사를 하지 않도록
		if (Other == this->Owner)
		{
			continue;
		}

		for (auto OtherComponent : Other->Components)
		{
			//상대방 엑터가 가진 여러 충돌중에서 충돌 컴포넌트를 가지고 있는 것만 골라낸다.
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				//좌표 기반 충돌 검사. 나와 상대방의 좌표가 일치하는 순간을 충돌로간주
				//조건 - 히트가 켜져있고 좌표가 같을 때
				if (OtherCollision->bIsGenerateHit &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					//리시브히트 함수 실행
					Other->ReceiveHit(Owner);
					Owner->ReceiveHit(Other);
				}
				
				//오버랩이 켜져있고 좌표가 같을 때
				if (OtherCollision->bIsGenerateOverlap &&
					Owner->GetX() == Other->GetX() && Owner->GetY() == Other->GetY())
				{
					//델리게이트(함수 포인터를 실행함) 실행. 
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

//dynamic_cast의 의미: 상대방 엑터가 가진 여러 부품 중에서 충돌 컴포넌트 타입인 것만 골라내는 안전한 형변환
//충돌 컴퍼넌트가 없다면 아더컬리션은 널이되어 아래 로직을 건너 뒴. 