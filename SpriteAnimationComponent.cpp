#include "SpriteAnimationComponent.h"
#include "GameplayStatics.h"
#include "Actor.h"

USpriteAnimationComponent::USpriteAnimationComponent()
{
}

USpriteAnimationComponent::~USpriteAnimationComponent()
{
}

//만화책 마냥 0.1 초마다 한 장씩 넘기는 역할
void USpriteAnimationComponent::Tick()
{
	__super::Tick(); //부모 (USpriteComponent)의 Tick도 실행해줘!

	//흐른 시간을 누적 ElapsedTime-> 지난 프레임 이후로 누적된 시간
	//ExecutionTime-> 다음 프레임으로 넘어갈 기준 시간
	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();

	//만약 설정한 시간이 지났다면
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++; //다음 그림 칸으로 이동
		SpriteIndexX = SpriteIndexX % 5;//0,1,2,3,4,순환 (5칸 짜리 애니메이션)
		ElapsedTime = 0; //시간 초기화
	}
}

//원하는 칸만 오려내기
//
void USpriteAnimationComponent::Render()
{
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5; //전체 이미지 가로를 5칸으로 나눔
	int SpriteSizeY = Image->h / 5;

	//어느 부위를 ㄱ져올 것인가?
	SDL_Rect SourceRect = { SpriteIndexX * SpriteSizeX, SpriteIndexY * SpriteSizeY, SpriteSizeX, SpriteSizeY };
	//어느 위치에 그릴 것인가
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	//부분만 출력
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);

}
