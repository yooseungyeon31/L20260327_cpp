#include "ResourceManager.h" //헤더는 설계도 ,cpp는 실제 동작
#include "Engine.h"
#include "SDL.h"

UResourceManager::UResourceManager()
{
}
//소멸자 메모리 해제
//
UResourceManager::~UResourceManager()
{
	for (auto Iter : Resources)
	{
		if (Iter.second.Image)
		{
			SDL_FreeSurface(Iter.second.Image);
		}
		if (Iter.second.Texture)
		{
			SDL_DestroyTexture(Iter.second.Texture);
		}
	}

	Resources.clear();
}

Resource& UResourceManager::LoadTexture(std::string Filename, bool bIsColorKey, Uint8 R, Uint8 G, Uint8 B)
{
	//함수 실행되면 맵을 확인, 맵에 있다면 바로 함수 끝냄. 없다면 아래 로직으로 새로 파일 읽기
	if (Resources.find(Filename) != Resources.end())
	{
		return Resources.find(Filename)->second;
	}

	Resource NewResource;

	//이미지 로드 및 투명화
	NewResource.Image = SDL_LoadBMP(Filename.c_str());
	if (bIsColorKey) //특정 색 투명 처리
	{
		SDL_SetColorKey(NewResource.Image, SDL_TRUE, SDL_MapRGB(NewResource.Image->format, R, G, B));
	}
	//GPU를 텍스처로 변환
	NewResource.Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), NewResource.Image);

	Resources[Filename] = NewResource;

	return Resources[Filename];
}