#pragma once
#include "Actor.h"
#include <xkeycheck.h>

class USpriteAnimationComponent;
class UCollisionComponent;

class AActor;


class APlayer : public AActor
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void ReceiveHit(class AActor* Other) override;

	void ProcessBeginOverlap(class AActor* OtherActor);

	

	USpriteAnimationComponent* SpriteAnimationComponent;
	UCollisionComponent* CollisionComponent;


protected:
	//Movement Component로 만들어야함..나중에..
	bool PredictMove(int InX, int InY);  //미리 가봄 갈 수 있냐 없냐 판단.

};