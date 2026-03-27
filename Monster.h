#pragma once
#include "Actor.h"
class AMonster :public AActor
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M');
	virtual ~AMonster();

	void BeginPlay() override;

	//오버라이드 재정의
	virtual void Tick() override;

	virtual void Render() override;
};

