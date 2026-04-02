#pragma once
#include <string>
#include <map> //맵 자료구조
#include "SDL.h"

struct SDL_Texture;
struct SDL_Surface;

struct Resource
{
	SDL_Surface* Image; //cpu에 저장할 픽셀 정보 -> 원본 데이터
	SDL_Texture* Texture; //GPU에 저장된 이미지-> 실제 게임화면에 그릴 때 속도가 빠름
};

class UResourceManager
{
public:
	UResourceManager();
	virtual ~UResourceManager();


	Resource& LoadTexture(std::string Filename, bool bIsColorKey = false, Uint8 R = 255, Uint8 G = 255, Uint8 B = 255);

protected:

	//맵에 이름이 있으면 새로 로드하지 않고 기존 데이터를 재사용
	std::map<std::string, Resource> Resources;

};