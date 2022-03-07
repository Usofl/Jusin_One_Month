#include <iostream>

using namespace std;

const int iSize = 5;

void InitArray(int(*iArray)[iSize]); // �迭�� ä���ִ� �Լ�
void PrintArray(int(*iArray)[iSize]);
void Swap(int* _iA, int* _iB);
void Moving(int iChoice, int(*iArray)[iSize], int* iX, int* iY);

void main()
{
	// 1. 0 ���� �̵�
	//  - 5 x 5 �迭�� 0 ~ 24���� ���
	//  - 2(�Ʒ�) 4(����) 6(������) 8(����)���� ���� 0�� �̵� (���ڰ� �ִ� ���������� ����)

	int iArray[iSize][iSize] = {};
	int iChoice = 0, iZeroX = 0, iZeroY = 0;

	InitArray(iArray);

	while (iChoice != -1)
	{
		system("cls");

		PrintArray(iArray);

		cin >> iChoice;

		Moving(iChoice, iArray, &iZeroX, &iZeroY);
	}
}

void InitArray(int(*iArray)[iSize])
{
	int iNumber = 0;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			iArray[i][j] = iNumber++;
		}
	}
}

void PrintArray(int(*iArray)[iSize])
{
	cout << "============================================" << endl;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cout << iArray[i][j] << "\t";
		}

		cout << endl;
	}
	cout << "============================================" << endl;
}

void Swap(int* _iA, int* _iB)
{
	int iTemp = *_iA;
	*_iA = *_iB;
	*_iB = iTemp;
}


void Moving(int iChoice, int(*iArray)[iSize], int* iX, int* iY)
{
	if (iChoice == 2)
	{
		if (*iY != (iSize - 1))
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY + 1][*iX]);
			*iY += 1;
		}
		else
		{
			Swap(&iArray[*iY][*iX], &iArray[0][*iX]);
			*iY = 0;
		}
	}
	else if (iChoice == 4)
	{
		if (*iX != 0)
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY][*iX - 1]);
			*iX -= 1;
		}
		else
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY][iSize - 1]);
			*iX = iSize - 1;
		}
	}
	else if (iChoice == 8)
	{
		if (*iY != 0)
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY - 1][*iX]);
			*iY -= 1;
		}
		else
		{
			Swap(&iArray[*iY][*iX], &iArray[iSize - 1][*iX]);
			*iY = iSize - 1;
		}
	}
	else if (iChoice == 6)
	{
		if (*iX != iSize - 1)
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY][*iX + 1]);
			*iX += 1;
		}
		else
		{
			Swap(&iArray[*iY][*iX], &iArray[*iY][0]);
			*iX = 0;
		}
	}
	else
	{
		return;
	}
}