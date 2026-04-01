#pragma once
#include <vector>
#include <Windows.h>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class UWorld;
class AActor;

struct SDL_Window;
struct SDL_Render;

class UEngine
{
protected:
	UEngine(); //외부에서 엔진을 호출할 수 없게 막아버림.

	static UEngine* Instance; //엔진의 유일한 주소값을 저장할 정적 변수

public:

	 ~UEngine();

	 //엔진 객체를 얻을 수 있는 통로
	 static UEngine* GetInstance()
	 {
		 if (Instance == nullptr) //인스텐스가 비지 않았다면, new로 객체 생성
		 {
			 Instance = new UEngine();
		 }
		 return Instance;


	 }

	void Init();
	void Term();

	void Run();

	inline UWorld* GetWorld()
	{
		return World;
	}

	static int KeyCode;

	//----더블버퍼링을 위해 만든

	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Flip();
	void TermBuffer();
	//----------------------
protected: 
	void Input();
	void Tick();
	void Render();
	

	class UWorld* World;

	int bIsRunning : 1;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRender;
	SDL_Event MyEvent;

};

//GEngine 이라는 별명생성. -> 매크로 같은 존재. 엔진 기능 호출 가능
#define GEngine UEngine::GetInstance()

//싱글톤 구조
/* 게임전체에서 엔진 객체는 단 하나만 존재해야한다.*/