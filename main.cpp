#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>
#include <algorithm>

using namespace std;

void Sort(int* a, int InLength)
{
	for (int i = 0; i < InLength; i++)
	{
		for (int j = i + 1; j < InLength; j++)
		{
			if (a[i] > a[j])
			{
				int Temp = a[i];
				a[i] = a[j];
				a[j] = Temp;
			}
		}

		cout << a[i] << " ";
	}
}




int main()
{
	int a[10] = { 9,1,3,5,4,6,7,8,2,10 };
	//search and sort
	//selection and bubble
	//첫번째 찍고 다음 숫자랑 비교해서 작으면 바꾸셈

	Sort(a, 10);

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


	//-----------------------------


	return 0;
} 

