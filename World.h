#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	//월드에서 엑터 스폰
	template<typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);

		return NewActor;
	}
	//----------------------------------
	template<typename T>
	AActor* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}
		return nullptr;
	}
	//----------------------------------
	//엔진 시작 하자마자 로딩
	void Load(std::string MapName);

	//엑터 목록을 외부에서 읽거나 접근 가능하도록
	inline std::vector<class AActor*>& GetActors()
	{
		return Actors;
	}

	void Tick();

	void Render();

	


protected:
	std::vector<class AActor*> Actors;

	void Sort(); //정렬 함수 선언
};

