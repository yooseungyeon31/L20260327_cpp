#pragma once 
#include "Component.h"

//충돌 컴포넌트
//충돌 감지 시스템을 담당함
class UCollisionComponent : public UComponent //컴포넌트 기능을 상속받음
{
public:

	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	int bIsGenerateOverlap = 1; //오버랩 생성 여부(두 객체 겹칠때)

	int bIsGenerateHit = 1; //히트 생성 여부(벽에 막히거나 물리적인 충돌 처리 결정
};

