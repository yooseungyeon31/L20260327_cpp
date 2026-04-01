#include <iostream>
#include "Engine.h"
#include "World.h"


#include "SDL.h"
//#include "SDL_main.h"

//사용할 라이브러리 복사하고 
// include 경로 추가, lib 경로 추가
// library 파일 등록 

//사용할 라이브러리 파일 추가
#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

using namespace std;
//-----------------------------------------
int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING); //윈도우 초기화

	//윈도우 가리키고 만들고
	SDL_Window* MyWindow = SDL_CreateWindow("Hello",100,100,640,480, SDL_WINDOW_SHOWN);

	//GPU, 붓
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	
	//계속 실행
	while (true)
	{
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent); //계속 물어보는거

		//이벤트 타임이 나가기면 나가기
		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}

		//GPU한테 보낼 명령어 모음 
		//이거하고 이거해라 적은것
		SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
		SDL_RenderClear(MyRender);
		

		//이제 보내기
		SDL_RenderPresent(MyRender);
	
	}
	//랜더 한거 삭제
	SDL_DestroyRenderer(MyRender);
	//윈도우 삭제
	SDL_DestroyWindow(MyWindow);

	

	SDL_Quit();

	return 0;
}

//int main()
//{
//	GEngine->GetWorld()->Load("level01.umap");
//
//	GEngine->Run();
//
//	delete GEngine;
//
//
//	return 0;
//} 

