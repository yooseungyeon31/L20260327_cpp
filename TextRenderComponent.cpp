#include "TextRenderComponent.h"
#include "SDL_ttf.h"
#include "Engine.h"
#include "Component.h"
#include "Actor.h"

UTextRenderComponent::UTextRenderComponent()
{
	
}

UTextRenderComponent::~UTextRenderComponent()
{
	if(Surface)
	{ 
	SDL_FreeSurface(Surface);
	}
	if (Texture)
	{
	SDL_DestroyTexture(Texture);
	}
}

void UTextRenderComponent::BeginPlay()
{
}

void UTextRenderComponent::Tick()
{
}

void UTextRenderComponent::Render()
{
	SDL_Rect DestinationRect = { Owner->GetX(), Owner->GetY(),Surface->w, Surface->h };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);

}

void UTextRenderComponent::SetText(std::string InText)
{
	Text = InText;
	//TTF-> 메모리 (BMP) ->Surfacee
	Surface = TTF_RenderText_Solid(GEngine->Font, Text.c_str(),SDL_Color{255,0,0,0});
	//그래픽 카드 넘겨주는 작업
	Texture =SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Surface);
}

