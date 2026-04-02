#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"

AActor::AActor(int InX, int InY, char InMesh): X(InX),Y(InY), Mesh(InMesh)
{
    R = 0;
    G = 0;
    B = 0;



}

AActor::~AActor()
{
    SDL_FreeSurface(Image);
    SDL_DestroyTexture(Texture);
}

void AActor::BeginPlay()
{

}

void AActor::Tick()
{

}
//엑터들 그리기 
void AActor::Render()
{
  
   // GEngine->Render(X, Y, Mesh);
    GEngine->Render(X, Y, Texture); //이제 render로 그리세요
}

void AActor::SetActorLocation(int NewX, int NewY)
{
    X = NewX;
    Y = NewY;
}

//로드 BMP 불러오기 함수
void AActor::Load(std::string Filename)
{
   Image = SDL_LoadBMP(Filename.c_str());

   //
   SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255,255,255));
    //텍스처 가져오기 함수
   Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image);
}