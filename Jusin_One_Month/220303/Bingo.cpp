#include <iostream>
#include <random>

using namespace std;

void InitArray(int(*iArray)[5], int iSize); // �迭�� ä���ִ� �Լ�
int RandomNum(bool bDraw = true); // ���� ���ڸ� ��ȯ�ϴ� �Լ� (true�� ��� 0~4, false�� ��� 1~25)
void Suhffle(int(*iArray)[5]); // �迭�� �����ִ� �Լ�
bool Cheak(int(*iArray)[5], int iSize, int _iNum); // �Լ��� �ߺ��� ���ڰ� ������� true �ƴҰ�� false
void Swap(int* _iA, int* _iB); // �� �ּ��� ���� �ٲ��ִ� �Լ�
void PrintArray(int(*iCArray)[5], int(*iPArray)[5], int iSize); // �迭�� ����ϴ� �Լ�
int PlayerInserting(); // �÷��̾ ���ڸ� �Է��ϴ� �Լ�
void InsertNumber(int(*iCArray)[5], int(*iPArray)[5], int iSize, int _iNum); // �Է��� ���ڸ� �������ִ� �Լ�
void BingoCheak(int(*iCArray)[5], int(*iPArray)[5], int iSize, int* _iComBingo, int* _iPlayerBingo); // ������ ������ üũ���ִ� �Լ�
bool CrossCheak(int(*iArray)[5], int iSize); // ���� ������ ���� �ϴܱ����� �밢���� üũ���ִ� �Լ�
bool CrossCheak2(int(*iArray)[5], int iSize); // ���� ������ ���� �ϴܱ����� �밢���� üũ���ִ� �Լ� 
bool HighCheak(int(*iArray)[5], int iSize, int iIndex); // ������ �Ʒ��� üũ���ִ� �Լ�
bool WideCheak(int(*iArray)[5], int iSize, int iIndex); // �������� ������ üũ���ִ� �Լ�

void main()
{
	// 2. ���� ����
	//  - 5 * 5 �迭�� �̿��� 1~25 ���ڸ� �����ϰ� ���
	//  - ���ڸ� �����ؼ� �Է��ϸ� ��ġ�ϴ� ���ڴ� *�� ���
	//  - *�� ǥ�õ� ���ڰ� ����, ����, �밢������ 5���� �ɶ����� ���� �ϳ� ����
	//  - 5���� �Ǹ� �¸��� ����
	// AI ���� �غ���

	int iComBingo = 0, iPlayerBingo = 0;

	int iComArray[5][5] = {};
	int iComSize = sizeof(iComArray[0]) / sizeof(int);
	InitArray(iComArray, iComSize);

	int iPlayerArray[5][5] = {};
	InitArray(iPlayerArray, iComSize);

	Suhffle(iComArray);
	Suhffle(iPlayerArray);

	while (true)
	{
		system("cls");

		PrintArray(iComArray, iPlayerArray, iComSize);

		cout << "Com : " << iComBingo << "                                     " << "Player : " << iPlayerBingo << endl;

		int iPlayerNumber = PlayerInserting();

		if (Cheak(iComArray, iComSize, iPlayerNumber))
		{
			InsertNumber(iComArray, iPlayerArray, iComSize, iPlayerNumber);
		}
		else
		{
			cout << "���� ���� �Դϴ�." << endl;
			system("pause");
			continue;
		}

		cout << endl;

		int iComNumber = RandomNum(false);

		while (!Cheak(iComArray, iComSize, iComNumber))
		{
			iComNumber = RandomNum(false);
		}

		BingoCheak(iComArray, iPlayerArray, iComSize, &iComBingo, &iPlayerBingo);

		if (!(iComBingo < 5) || !(iPlayerBingo < 5))
		{
			break;
		}

		InsertNumber(iComArray, iPlayerArray, iComSize, iComNumber);
		cout << "��ǻ�Ͱ� �� ���ڴ� " << iComNumber << endl;
		cout << endl;

		BingoCheak(iComArray, iPlayerArray, iComSize, &iComBingo, &iPlayerBingo);

		if (!(iComBingo < 5) || !(iPlayerBingo < 5))
		{
			break;
		}

		system("pause");
	}

	if (iPlayerBingo >= 5)
	{
		cout << "�¸� �ϼ̽��ϴ�." << endl;
	}
	else
	{
		cout << "�й� �ϼ̽��ϴ�." << endl;
	}
}

void InitArray(int(*iArray)[5], int iSize)
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

int RandomNum(bool bDraw)
{
	int iNum = 0;

	std::random_device rd;

	std::mt19937 gen(rd());

	if (bDraw)
	{
		std::uniform_int_distribution<int> dis(0, 4);
		iNum = dis(gen);
	}
	else
	{
		std::uniform_int_distribution<int> dis(1, 25);
		iNum = dis(gen);
	}

	return iNum;
}

void Suhffle(int(*iArray)[5])
{
	for (int i = 0; i < 500; ++i)
	{
		Swap(&iArray[RandomNum()][RandomNum()], &iArray[RandomNum()][RandomNum()]);
	}
}

bool Cheak(int(*iArray)[5], int iSize, int _iNum)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (iArray[i][j] == _iNum)
			{
				return true;
			}
		}
	}
	return false;
}

void Swap(int* _iA, int* _iB)
{
	int iTemp = *_iA;
	*_iA = *_iB;
	*_iB = iTemp;
}

void PrintArray(int(*iCArray)[5], int(*iPArray)[5], int iSize)
{
	cout << "=================================================================" << endl;
	cout << "Com                                     " << "Player" << endl;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (iCArray[i][j] != 0)
			{
				cout << iCArray[i][j] << "\t";
			}
			else
			{
				cout << "*" << "\t";
			}
		}
		cout << "|\t";
		for (int j = 0; j < iSize; ++j)
		{
			if (iPArray[i][j] != 0)
			{
				cout << iPArray[i][j] << "\t";
			}
			else
			{
				cout << "*" << "\t";
			}
		}

		cout << endl;
	}
}

int PlayerInserting()
{
	int iNum = 0;
	cout << endl;
	cout << "����� �����Դϴ�." << endl;
	cin >> iNum;

	return iNum;
}

void InsertNumber(int(*iCArray)[5], int(*iPArray)[5], int iSize, int _iNum)
{
	int iCNum = 0;
	int iPNum = 0;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (iCArray[i][j] == _iNum)
			{
				Swap(&iCArray[i][j], &iCNum);
			}

			if (iPArray[i][j] == _iNum)
			{
				Swap(&iPArray[i][j], &iPNum);
			}
		}
	}
}

void BingoCheak(int(*iCArray)[5], int(*iPArray)[5], int iSize, int* _iComBingo, int* _iPlayerBingo)
{
	int iBingo = 0;
	*_iComBingo = 0;
	*_iPlayerBingo = 0;

	if (CrossCheak(iCArray, iSize))
	{
		*_iComBingo += 1;
	}

	if (CrossCheak2(iCArray, iSize))
	{
		*_iComBingo += 1;
	}

	if (CrossCheak(iPArray, iSize))
	{
		*_iPlayerBingo += 1;
	}

	if (CrossCheak2(iPArray, iSize))
	{
		*_iPlayerBingo += 1;
	}

	for (int i = 0; i < iSize; ++i)
	{
		if (iCArray[0][i] == 0)
		{
			if (HighCheak(iCArray, iSize, i))
			{
				*_iComBingo += 1;
			}
		}

		if (iCArray[i][0] == 0)
		{
			if (WideCheak(iCArray, iSize, i))
			{
				*_iComBingo += 1;
			}
		}

		if (iPArray[0][i] == 0)
		{
			if (HighCheak(iPArray, iSize, i))
			{
				*_iPlayerBingo += 1;
			}
		}

		if (iPArray[i][0] == 0)
		{
			if (WideCheak(iPArray, iSize, i))
			{
				*_iPlayerBingo += 1;
			}
		}
	}
}

bool CrossCheak(int(*iArray)[5], int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		if (iArray[i][i] != 0)
		{
			return false;
		}
	}
	return true;
}

bool CrossCheak2(int(*iArray)[5], int iSize)
{
	int iNum = 4;
	for (int i = 0; i < iSize; ++i)
	{
		if (iArray[i][iNum - i] != 0)
		{
			return false;
		}
	}
	return true;
}

bool HighCheak(int(*iArray)[5], int iSize, int iIndex)
{
	for (int i = 1; i < iSize; ++i)
	{
		if (iArray[i][iIndex] != 0)
		{
			return false;
		}
	}
	return true;
}

bool WideCheak(int(*iArray)[5], int iSize, int iIndex)
{
	for (int i = 1; i < iSize; ++i)
	{
		if (iArray[iIndex][i] != 0)
		{
			return false;
		}
	}
	return true;
}