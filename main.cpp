#include  <iostream>
#include "Engine.h"
#include "World.h"
#include "MyGM.h"
#include "Component.h"
#include <functional>



void Test()
{
	std::cout << "Test" << std::endl;
}



int SDL_main(int argc, char* argv[])
{
	//함수 포인터
	//callback
	//classs 결합도를 낮춘다.
	//그냥 주소만 가지고 넣는거다. 별 기능이 없어서 funtional 을 사용한다.
	//여러개 등록했다가 하나만 뺴고 그런거 가능. 
	//
	//void (*fn)();
	//fn = Test;

	//std::function<void()> f1;
	//int A = 10;
	////인자, 반환형, 함수
	//f1 = [&]()-> void {
	//	std::cout << A << std::endl;
	//	};
	//f1();
	//OnActorBeginOverlap = ProcessBeginOverlap;

	//OnActorBeginOverlap(nullptr);



	
	GEngine->GetWorld()->SetGameMode(new AMyGM());
	GEngine->GetWorld()->Load("level01.umap");


	GEngine->Run();

	delete GEngine;

	return 0;
}