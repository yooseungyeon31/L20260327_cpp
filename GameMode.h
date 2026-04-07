#pragma once
#include "Actor.h"

//게임모드 클래스는 게임의 승리 조건과 패배조건을 실시간으로 감시하는 심판 역할
//이김, 짐 판단

//AACtor을 상속받음. 즉 게임 월드에 존재할 수 있는 하나의 물체임.
class AGameMode : public AActor
{
public:
	AGameMode();
	virtual ~AGameMode();

	virtual void Tick() override; //실시간 상황 체크

};

