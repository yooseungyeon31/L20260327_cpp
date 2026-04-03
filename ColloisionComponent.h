#pragma once 
//충돌 컴포넌트
#include "Component.h"
class UColloisionComponent : public UComponent
{
public:

	UColloisionComponent();
	virtual ~UColloisionComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	int bIsGenerateOverlap = 1;

	int bIsGenerateHit = 1;
};

