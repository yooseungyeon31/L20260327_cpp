#pragma once
#include "Actor.h"

class USpriteAnimationComponent;

class APlayer : public AActor
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	void ProcessBeginOverlap(class AActor* OtherActor);

	USpriteAnimationComponent* SpriteAnimationComponent;


protected:


};