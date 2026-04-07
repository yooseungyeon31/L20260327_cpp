#include "SpriteComponent.h"
#include "Engine.h"
#include "Actor.h"

USpriteComponent::USpriteComponent()
{
}

USpriteComponent::~USpriteComponent()
{
}
//함수가 비어있는 이유는 이 스프라이트 컴포넌트가
//그리는 일에만 집중하고 있기 때문이다. 
//부모인 UComponent에서 무조건 만들어라 라고 시키기 떄문에(순수가상함수) 형태만이라고 구현해 둔 것
void USpriteComponent::BeginPlay()
{
}

void USpriteComponent::Tick()
{
}

void USpriteComponent::Render()
{
	int TileSize = 30; //한 칸의 크기를 30픽셀로 정함
	//그림이 그려질 위치와 크기를 결정
	//내 주인이 어디있지? 를 알아야 그 위치에 그림을 그릴 수 있다. 
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	//실제로 화면에 그리는 명령
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
}