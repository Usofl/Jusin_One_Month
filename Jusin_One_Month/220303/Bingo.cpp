#include <iostream>
#include <random>

using namespace std;

void InitArray(int(*iArray)[5], int iSize); // 배열을 채워주는 함수
int RandomNum(bool bDraw = true); // 랜덤 숫자를 반환하는 함수 (true일 경우 0~4, false일 경우 1~25)
void Suhffle(int(*iArray)[5]); // 배열을 섞어주는 함수
bool Cheak(int(*iArray)[5], int iSize, int _iNum); // 함수에 중복된 숫자가 있을경우 true 아닐경우 false
void Swap(int* _iA, int* _iB); // 두 주소의 값을 바꿔주는 함수
void PrintArray(int(*iCArray)[5], int(*iPArray)[5], int iSize); // 배열을 출력하는 함수
int PlayerInserting(); // 플레이어가 숫자를 입력하는 함수
void InsertNumber(int(*iCArray)[5], int(*iPArray)[5], int iSize, int _iNum); // 입력한 숫자를 삽입해주는 함수
void BingoCheak(int(*iCArray)[5], int(*iPArray)[5], int iSize, int* _iComBingo, int* _iPlayerBingo); // 빙고의 개수를 체크해주는 함수
bool CrossCheak(int(*iArray)[5], int iSize); // 좌측 위부터 우측 하단까지의 대각선을 체크해주는 함수
bool CrossCheak2(int(*iArray)[5], int iSize); // 우측 위부터 좌측 하단까지의 대각선을 체크해주는 함수 
bool HighCheak(int(*iArray)[5], int iSize, int iIndex); // 위에서 아래로 체크해주는 함수
bool WideCheak(int(*iArray)[5], int iSize, int iIndex); // 좌측에서 우측을 체크해주는 함수

void main()
{
	// 2. 빙고 게임
	//  - 5 * 5 배열을 이용해 1~25 숫자를 랜덤하게 출력
	//  - 숫자를 선택해서 입력하면 일치하는 숫자는 *로 출력
	//  - *로 표시된 숫자가 가로, 세로, 대각선으로 5개가 될때마다 빙고가 하나 증가
	//  - 5빙고가 되면 승리로 종료
	// AI 삽입 해보자

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
			cout << "없는 숫자 입니다." << endl;
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
		cout << "컴퓨터가 고른 숫자는 " << iComNumber << endl;
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
		cout << "승리 하셨습니다." << endl;
	}
	else
	{
		cout << "패배 하셨습니다." << endl;
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
	cout << "당신의 차례입니다." << endl;
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