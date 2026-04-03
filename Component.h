#pragma once

//이걸 상속받는 사람들한테 밑에 함수를 무조건 만들라고 강요원함. 
//추상 클래스
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수가상함수
	virtual void BeginPlay() = 0;

	virtual void Tick()=0;

	
};

