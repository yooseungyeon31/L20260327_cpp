#pragma once
class AActor
{

public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();

	//오버라이드 재정의
	virtual void Tick();

	virtual void Render();

	void SetActorLocation(int NewX, int NewY);

	inline const int GetZOrder() //순서
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;
	int ZOrder=0 ; //먼저 그리는 순서관련 변수
	char Mesh;

};

