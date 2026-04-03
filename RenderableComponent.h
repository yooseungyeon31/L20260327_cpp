#pragma once
//인터페이스로 사용
//C++은 인터페이스가 없음 
//abstract class, pure virtual function

class IRenderableComponent
{
public:
	virtual void Render() = 0;
};

