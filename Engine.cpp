#include "Engine.h"
#include <conio.h>
#include "Actor.h"
#include "World.h"

#include "SDL.h"

UEngine* UEngine::Instance = nullptr;

int UEngine::KeyCode = 0;

UEngine::UEngine()
{
	Init();

}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING); //윈도우 초기화

	//윈도우 가리키고 만들고
	MyWindow = SDL_CreateWindow("Hello", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	//GPU, 붓
	MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	bIsRunning = true;

	InitBuffer(); //버퍼도 초기화

	World = new UWorld();
}


void UEngine::Term()
{

	//랜더 한거 삭제
	SDL_DestroyRenderer(MyRender);
	//윈도우 삭제
	SDL_DestroyWindow(MyWindow);


	SDL_Quit();

	delete World;

	TermBuffer();

	World = nullptr;

}

void UEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);

		Input();
		Tick();
		Render();
	}
}

//---------------------------------------------------

void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);

}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;

}

void UEngine::TermBuffer()

{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}
//-------------------------------------------------------
void UEngine::Input()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
}


void UEngine::Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{
		bIsRunning = false;
	}

	World->Tick();
}

void UEngine::Render()
{

	//GPU한테 보낼 명령어 모음 
	//이거하고 이거해라 적은것
	//CPU가 하는건 GPU가 할 일을 적는 것.
	SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
	SDL_RenderClear(MyRender);

	World->Render();

	//그려CPU -> GPU
	SDL_RenderPresent(MyRender);

}
