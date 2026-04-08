#include "Engine.h"

#include "Actor.h"
#include "World.h"
#include "SDL.h"
#include "ResourceManager.h"

UEngine* UEngine::Instance = nullptr;





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
	SDL_Init(SDL_INIT_EVERYTHING); //SDL 시스템 가동

	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	//윈도우와 렌더링 생성
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED| SDL_RENDERER_TARGETTEXTURE); //그래픽카드
	//MyRender = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_SOFTWARE);
	
	
	Mix_Init(MIX_INIT_MP3);



	char* Device = nullptr;
	int Frequency = 0;
	Uint16 Format = 0;
	int Channels = 0;
	int Result = Mix_OpenAudioDevice(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096, Device, SDL_AUDIO_ALLOW_ANY_CHANGE);


	Result = Mix_QuerySpec(&Frequency, &Format, &Channels);
	if (Result == 1)
	{
		int Success = Mix_OpenAudio(Frequency, Format, Channels, 4096);
		if (Success == -1)
		{
			SDL_Log("Sound Card Error");
		}
	}
	TTF_Init();

	Font = TTF_OpenFont("./Data/MaruBuri-Bold.ttf", 32);

	//리소스 매니저 생성
	ResourceManager = new UResourceManager();

	bIsRunning = true;

	InitBuffer();

	World = new UWorld();
}

void UEngine::Term()
{
	//리소스 매니저 바꾸면 된다. 
	if (Font)
	{
		TTF_CloseFont(Font);
	}

	Mix_CloseAudio();
	TTF_Quit();
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	delete World;
	TermBuffer();
	World = nullptr;

	delete ResourceManager;
}


void UEngine::Run()
{
	World->BeginPlay();
	
	Uint64 LastTime;
	
	while (bIsRunning)
	{
		
		LastTime = SDL_GetTicks64();


		SDL_PollEvent(&MyEvent);
		Input();
		Tick();
		Render();
		//초단위로 바꾸려면 ? 
		DeltaSeconds = (float)(SDL_GetTicks64() - LastTime)/1000.0f; //m/s 
		//SDL_Log("%f s",DeltaSeconds); //알아서 딜레이를 해줌
	}
}

void UEngine::Stop()
{
	bIsRunning = false;
}


void UEngine::InitBuffer()
{
	//ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	//CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	//ConsoleCursorInfo.dwSize = 1;
	//ConsoleCursorInfo.bVisible = FALSE;

	//SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	//SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);

}

void UEngine::Clear()
{
	//지우는걸 clear로 옮겨줌
	//CPU하는건 GPU가 할일을 적는거야. 많이 많이 많이
    //GPU 한테 보낼 명령어 모음
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 255);
	SDL_RenderClear(MyRenderer);

	/*DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);*/
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	/*char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);*/
}

void UEngine::Render(int InX, int InY, int R, int G, int B)
{
	int TileSize = 30;
	SDL_SetRenderDrawColor(MyRenderer, R, G, B, 255);
	//SDL_RenderDrawPoint(MyRender, InX, InY);
	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderFillRect(MyRenderer, &MyRect);
}

void UEngine::Render(int InX, int InY, SDL_Texture* InTexture)
{
	int TileSize = 30;

	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderCopy(MyRenderer, InTexture, nullptr, &MyRect);
}

//이건 필요없음. 
void UEngine::Flip()
{
	/*SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;*/
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
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


	World->Render();

	//그려CPU -> GPU
	SDL_RenderPresent(MyRenderer);
}