#include <iostream>

using namespace std;

void InitArray(int(*iArray)[4], int iSize);
void Turn(int(*iArray)[4], int iSize);
void Swap(int* _iA, int* _iB);
void PrintArray(int(*iArray)[4], int iSize);


void main()
{
	// 1. 2차원 배열을 이용하여 90도 시계방향으로 4회전하여 출력하기 4*4
	// 1 2 3       7 4 1             9 8 7
	// 4 5 6   ->  4 5 2 (1회전) ->  6 5 4
	// 7 8 9       9 6 3             3 2 1

	int iFArray[4][4] = {};

	InitArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

	PrintArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

	cout << endl;
	cout << "90도 회전" << endl;

	Turn(iFArray, sizeof(iFArray[0]) / sizeof(int));

	PrintArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

	cout << endl;
	cout << "180도 회전" << endl;

	Turn(iFArray, sizeof(iFArray[0]) / sizeof(int));

	PrintArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

	cout << endl;
	cout << "270도 회전" << endl;

	Turn(iFArray, sizeof(iFArray[0]) / sizeof(int));

	PrintArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

	cout << endl;
	cout << "360도 회전" << endl;

	Turn(iFArray, sizeof(iFArray[0]) / sizeof(int));

	PrintArray(iFArray, sizeof(iFArray[0]) / sizeof(int));

}

void InitArray(int(*iArray)[4], int iSize)
{
	int iNumber = 1;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			iArray[i][j] = iNumber++;
		}
	}
}

void Turn(int(*iArray)[4], int iSize)
{
	int turn = iSize - 1;
	int iFArray[4][4] = {};

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			iFArray[j][turn - i] = iArray[i][j];
		}
	}

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			Swap(&iFArray[i][j], &iArray[i][j]);
		}
	}
}

void Swap(int* _iA, int* _iB)
{
	int iTemp = *_iA;
	*_iA = *_iB;
	*_iB = iTemp;
}

void PrintArray(int(*iArray)[4], int iSize)
{
	cout << "==========================" << endl;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}
}