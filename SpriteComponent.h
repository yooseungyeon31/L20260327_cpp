#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

//게임 속 물체룰 화면에 그리는 기능을 담당하는 함수.
//USpriteComponent는 UComponent의 자식으로서, 주인(Actor)의 위치 정보를 받아와서 SDL 
// 라이브러리를 통해 화면에 텍스처를 찍어주는 역할


//두가지 부모를 상속받고 있음. 실제로 그림은 여기서 그림
//UComponent 게임의 부품으로서, 비긴플레이와 틱을 실행해야 할 의무가 있음. 
//IRenderableComponent 는 화면에 그려질 수 있는 것 이라는 인터페이스를 약속받아 Render 함수를 반드시 만들어야함
class USpriteComponent : public UComponent, public IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();

	//UComponent狼 备泅, Abstract Class, 
	virtual void BeginPlay() override;

	virtual void Tick() override;

	//	//IRenderableComponent를 구현, Interface라는 구현(
//	//c++문법이 없음, 블루프린트 시샵, 자바에만 있음
	virtual void Render() override;

	int ZOrder = 0;


	SDL_Surface* Image;
	SDL_Texture* Texture;
};
