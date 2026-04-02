#include <iostream>
#include "Engine.h"
#include "World.h"


using namespace std;

typedef unsigned char byte;
using byte = unsigned char;

int SDL_main(int argc, char* argv[])
{
////비트연산
////정수 X 01010 이진수
//	byte Number1 = 0b000000001; //0000 0001
//	byte Number2 = 0b000000010;
//	SDL_Log("%d", Number1);
//
//	Number1 = Number1 << 1; //shift 연산자 0000 0010
//	SDL_Log("%d", Number1);
//
//	Number1 = Number1 << 1; //shift 연산자 0000 0100
//	SDL_Log("%d", Number1);
//
//	byte Number3 = Number1 | Number2;

	GEngine->GetWorld()->Load("level01.umap");

	GEngine->Run();

	delete GEngine;

	return 0;
}


