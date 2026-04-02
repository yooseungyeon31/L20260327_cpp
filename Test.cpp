//#include <iostream>
//
//using namespace std;
//
//// 숫자 X보다 크거나 같은 수 중 가장 작은 
////2의 승수가 NPOT(Next Power of Two) 라고 할 때,
////주어진 숫자 N개의 NPOT을 구하여 모두 XOR한 값 구하기
//using uint64 = unsigned long long;
//
//int main()
//{
//
//	//int N; //숫자 개수
//	//int X; // 숫자
//	//int Result;
//	//
//
//	//for (int i = 0; i < N; i++)
//	//{
//	//	cout << "숫자 입력하세요 :" << " ";
//	//	cin >> X;
//
//	//	for (int j = 0; j < 63; j++)
//	//	{
//	//		if ((1L << j) < F && F <= (1L << j + 1))
//	//		{
//	//			Result = Result ^ (1 << j + 1);
//
//	//			break;
//	//		}
//	//	}
//	//}
//
//	//return 0;
//
//
//	//-----------------------------------------------
//	//빨리계산 을 해야한다. 비트연산 해야한다. 
//	uint64 X = 0;
//	int N = 0;
//	int Result = 0;
//	cin >> N;
//
//	int A = 1;
//	A << 1; //A의값은 2
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> X;
//		for (int j = 0; j < 63; j++)
//		{
//			//if (X < pow(2, j)) //제곱하는거 2의 j승
//			//if(X<(1<<j)) //이렇게도 제곱수 구하는 방법임
//			uint64 NPOT = (1 << j);
//			if(X<NPOT)
//			{
//				Result = Result ^ NPOT;
//				break; 
//			}
//		}
//	}
//
//	cout << Result;
//
//
//
//	return 0;
//}
//
//
//
//
