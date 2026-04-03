#pragma once
#include "Character.h"
#include <xkeycheck.h>

class USpriteAnimationComponent;
class UCollisionComponent;
class AActor;


class APlayer : public ACharacter
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





};