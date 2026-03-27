#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>
#include <algorithm>

using namespace std;

//void Sort(int* a, int InLength)
//{
//	for (int i = 0; i < InLength; i++)
//	{
//		for (int j = i + 1; j < InLength; j++)
//		{
//			if (a[i] > a[j])
//			{
//				int Temp = a[i];
//				a[i] = a[j];
//				a[j] = Temp;
//			}
//		}
//
//		cout << a[i] << " ";
//	}
//}
void Sort(int* InData, int InLength, int (*Compare)(int A, int B))
{
	for (int FirstIndex = 0; FirstIndex < InLength; ++FirstIndex)
	{
		for (int SecondIndex = 0; SecondIndex < InLength; ++SecondIndex)
		{
			if (Compare(InData[FirstIndex], InData[SecondIndex]))
			{
				int Temp = InData[FirstIndex];
				InData[FirstIndex] = InData[SecondIndex];
				InData[SecondIndex] = Temp;
			}
		}
	}
}

bool bConnection = true;

int CompleteCallback()
{
	cout << "접속 완료" << endl;

	return 0;
}

void Connect(int (*Complete)())
{
	//callback
	if (bConnection)
	{
		Complete();
	}
}


int Ascending(int A, int B)
{
	if (A < B)
	{
		return 1;
	}
	else if (A == B)
	{
		return 0;
	}

	return -1;
}

int Decending(int A, int B)
{
	if (A < B)
	{
		return -1;
	}
	else if (A == B)
	{
		return 0;
	}

	return 1;
}
int main()
{
	int a[10] = { 9,1,3,5,4,6,7,8,2,10 };
	//search and sort
	//selection and bubble
	//첫번째 찍고 다음 숫자랑 비교해서 작으면 바꾸셈

	//Sort(a, 10);

	//메인안에 넣은 버전
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = i + 1; j < 10; j++)
	//	{
	//		if (a[i] > a[j])
	//		{
	//			int Temp = a[i];
	//			a[i] = a[j];
	//			a[j] = Temp;
	//		}
	//	}

	//	cout << a[i] << " ";
	//}
	//-------------------------------

	Connect(CompleteCallback);



	int Data[8] = { 9, 1, 3, 5, 7, 8, 2, 10 };
	//search and sort
	//selection and bubble
	//1 9 3 5 4 6 7 8 2 10
	//1 2 9 5 4 6 7 8 3 10

	int Number = 0;

	//일급함수 -> 함수도 변수에 저장 가능함. 라는 뜻.
	//aito Compare 이렇게 할수도 있음. 
	//내 마음대로 호출할 수도 있다.
	int (*Compare)(int A, int B) = [](int A, int B) -> int {
		
		 return 0;
		};

	Compare(1, 2);

	//람다 함수, 익명 함수, C++ 14 이상
	//함수 이름 없이 선언할 수 있다.
	Sort(Data, 8, [](int A, int B) -> int {
		if (A > B)
		{
			return 1;
		}
		else if (A == B)
		{
			return 0;
		}

		return -1;
		}
	);


	for (int i = 0; i < 8; ++i)
	{
		cout << Data[i] << ",";
	}

	//-----------------------------


	return 0;
} 

