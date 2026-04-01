#pragma once

#include <vector>
#include <Windows.h>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class AActor;
class UWorld;


class UEngine
{
protected:
	UEngine();

	static UEngine* Instance;

public:
	~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
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

	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Flip();
	void TermBuffer();

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