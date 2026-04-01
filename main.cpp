#include <iostream>
#include "Engine.h"
#include "World.h"
#include <math.h>

#include <random>


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
	//난수 만들어주는애 . 랜덤 만들어주는 거 많음
	//더 좋은 난수를 만들기 위해 사용
	std::random_device RandomDevice;
	std::mt19937 RandomGenerator(RandomDevice());

	std::uniform_int_distribution<int> DistX(0, 640);
	std::uniform_int_distribution<int> DistY(0, 480);

	std::uniform_int_distribution<int> DistR(0, 255);
	std::uniform_int_distribution<int> DistG(0, 255);
	std::uniform_int_distribution<int> DistB(0, 255);
	std::uniform_int_distribution<int> DistA(0, 255);


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
		//CPU가 하는건 GPU가 할 일을 적는 것.
		SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
		SDL_RenderClear(MyRender);

		//어떻게 그릴지 명령어 GPU
		//빨간색 붓 고르고
		//for (int i = 0; i < 100; ++i)
		//{
		//	SDL_SetRenderDrawColor(MyRender, DistR(RandomGenerator), DistG(RandomGenerator), DistB(RandomGenerator), DistA(RandomGenerator));
		
		//	//사각형 그려
		//	SDL_Rect MyRect = { DistX(RandomGenerator), DistY(RandomGenerator), DistX(RandomGenerator), DistY(RandomGenerator) };
		//	SDL_RenderFillRect(MyRender, &MyRect);
		//}

		SDL_SetRenderDrawColor(MyRender, 255, 0, 0, 0);

		int Radius = 200;
		int CenterX = 500;
		int CenterY = 500;
		int Size = 15;

		for (int Theta = 0; Theta <= 360; Theta+=Size)
		{
		
			float Radian1 = (float)Theta  * 3.14592f / 180.0f;
			float Radian2= (float)(Theta+Size) * 3.141592f / 180.0f;
			int X1 = Radius * SDL_cos(Radian1) + CenterX;
			int Y1 = Radius * SDL_sin(Radian1) + CenterY;
			int X2 = Radius * SDL_cos(Radian2) + CenterX;
			int Y2 = Radius * SDL_sin(Radian2) + CenterY;
			//SDL_RenderDrawPoint(MyRender, X, Y);
			SDL_RenderDrawLine(MyRender, X1, Y1, X2, Y2);
		}

		//
		//int rad = 50; // 원의 반지름 설정
		//int x = 200;   // 원의 중심 X 좌표
		//int y = 300;   // 원의 중심 Y 좌표

		////동그라미 그리기//
		// 
		//int rad = 50; // 원의 반지름 설정
		//int x = 200;   // 원의 중심 X 좌표
		//int y = 300;   // 원의 중심 Y 좌표

		//for (int i = 0; i < 180; i++)
		//{
		//	SDL_SetRenderDrawColor(MyRender, 255, 0, 0, 255);

		//	int x1 = sin(3.14 / 180 * i) * rad;
		//	int y1 = cos(3.14 / 180 * i) * rad;
		//	int x2 = sin(3.14 / 180 * (360-i)) * rad;
		//	int y2 = cos(3.14 / 180 * (360 - i)) * rad;

		//	SDL_RenderDrawLine(MyRender, x1 + x, y1 + y, x2 + x, y2 + y);
		//}


		//----노란색 사각형 띄우기----//
		//SDL_Rect rect = { 250,  150, 150 , 150 };
		//
		//SDL_SetRenderDrawColor(MyRender, 255, 255, 0, 255); //노란색 사각형

		//SDL_RenderFillRect(MyRender, &rect);
		//----------------------------

		//이제 보내기 //그려라 GPU에
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

