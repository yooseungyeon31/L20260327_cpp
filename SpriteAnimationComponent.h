#pragma once
#include "SpriteComponent.h"

//애니메이션 기능이 추가된 스프라이트. 부품
//여기서는 USpriteComponent 이거를 상속받았다. 
//즉, 그리는 기능은 그대로 물려받고 거기에 움직이는 로직만 더한 것
class USpriteAnimationComponent : public USpriteComponent
{
public:
	USpriteAnimationComponent();
	virtual ~USpriteAnimationComponent();

	virtual void Tick() override;

	virtual void Render() override;

	int SpriteIndexX = 0;
	int SpriteIndexY = 0;

	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;

protected:



};

