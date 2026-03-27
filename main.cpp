#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>
#include <algorithm>

using namespace std;


////비교 함수 
//bool compare(int a, int b)
//{
//	return a < b;
//}

int main()
{
	int a[10] = { 9,1,3,5,4,6,7,8,2,10 };
	//search and sort
	//selection and bubble
	//첫번째 찍고 다음 숫자랑 비교해서 작으면 바꾸셈

	//bool compare (int a, int b);


	//sort(a, a+10, compare);

	//for (int i = 0; i < 10; i++)
	//{
	//	
	//	cout << a[i] << " ";

	//}

	//-----------------------------
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
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

	return 0;
} 