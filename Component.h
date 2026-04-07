#pragma once

//우리 게임의 모든 부품은 이런 모양이어야해. 라고 규칙을 정하는 파일.
//왜 필요하지?
//->  게임 엔진은 매 프레임마다 수천 개의 컴포넌트를 업데이트 해야함. 컴포넌트 마다 이름이 다르면
//관리하기 힘들다. 그래서 이거를 상속받으면 엔진 내부가 어떻든 너희는 모두
//Tick을 가지고 있구나. 라고 믿고 한꺼번에 실행한다.

//이걸 상속받는 사람들한테 밑에 함수를 무조건 만들라고 강요 원함. 
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

	virtual void BeginPlay() = 0; //이 클래스는 껍데기일 뿐이니 이걸 상속받는 네가 반드시
	//알맹이를 채워라 라는 의미 

	virtual void Tick() = 0;

	class AActor* Owner; //이 부품이 어던 물체에 붙어있는지 알려주는 정보이다. 


};

