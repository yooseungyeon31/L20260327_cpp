#pragma once

//이걸 상속받는 사람들한테 밑에 함수를 무조건 만들라고 강요원함. 
//추상 클래스
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수가상함수
	//pure virtual function
	//이클래스는 내가 다른 사람한테 상속으로 하라고 강제할게.
	//

	virtual void BeginPlay() = 0;

	virtual void Tick()=0;

	class AActor* Owner;

	
};

