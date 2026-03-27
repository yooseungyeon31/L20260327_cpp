#include "Actor.h"
#include <iostream>
#include <Windows.h>
#include "Engine.h"

AActor::AActor(int InX, int InY, char InMesh): X(InX),Y(InY), Mesh(InMesh)
{

}

AActor::~AActor()
{
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
    //COORD Coordinate;
    //Coordinate.X = X;
    //Coordinate.Y = Y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);
   


    //std::cout << Mesh;

    GEngine->Render(X, Y, Mesh);
}

void AActor::SetActorLocation(int NewX, int NewY)
{
    X = NewX;
    Y = NewY;
}