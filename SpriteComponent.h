#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

class USpriteComponent : public UComponent, IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();

	//UComponent狼 备泅, Abstract Class, 
	virtual void BeginPlay() override;

	virtual void Tick() override;


	virtual void Render() override;

	int ZOrder = 0;


	SDL_Surface* Image;
	SDL_Texture* Texture;
};
//class USpriteComponent : public UComponent, IRenderableComponent
//{
//public:
//	USpriteComponent();
//	virtual ~USpriteComponent();
//
//	//UComponent 의 구현, Abstract Class
//	virtual void BeginPlay() override;
//
//	virtual void Tick() override;
//
//	//IRenderableComponent를 구현, Interface라는 구현(
//	//c++문법이 없음, 블루프린트 시샵, 자바에만 있음
//	virtual void Render() override;
//
//	int ZOrder = 0;
//
//	SDL_Surface* Image;
//	SDL_Texture* Texture;
//
//};

