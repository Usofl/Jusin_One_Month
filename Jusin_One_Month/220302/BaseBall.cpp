#include <iostream>
#include <random>

using namespace std;

int randomNum();
void Draw(int* _pArray);
bool DrawCheak(const int* _pArray, const int _iNum);
void Player(int* _pArray);
bool GameCheak(const int* _pCom, const int* _pPlayer);

void main()
{
	// 야구게임
	// 1~9까지의 무작위 숫자 3개를 추출
	// 정렬 x
	// 입력하는 숫자와 무작위 숫자의 값과 자리가 일치하면 스트라이크, 값만 일치하면 볼
	// 매회 입력 후 몇 스트라이크 몇 볼 출력
	// 9라운드 진행, 3스트라이크를 못만들면 패배

	int iCom[3] = {};
	int iPlayer[3] = {};
	int iRound = 0;

	Draw(iCom);


	cout << "컴퓨터의 숫자는 ( ";
	for (int i = 0; i < 3; ++i)
	{
		cout << iCom[i] << " ";
	}
	cout << ") 입니다." << endl;

	while (9 > iRound)
	{
		Player(iPlayer);

		cout << iRound + 1 << "번째 라운드 ";

		if (GameCheak(iCom, iPlayer))
		{
			break;
		}
		cout << endl;

		iRound++;
	}
}

int randomNum()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(1, 9);

	return dis(gen);
}

void Draw(int* _pArray)
{
	int* pArray = _pArray;
	int iNum = 0;
	int iCount = 0;

	while (3 > iCount)
	{
		iNum = randomNum();

		if (DrawCheak(_pArray, iNum))
		{
			*pArray = iNum;
			pArray++;
			iCount++;
		}
	}
}

bool DrawCheak(const int* _pArray, int _iNum)
{
	const int* pArray = _pArray;

	for (int i = 0; i < 3; ++i)
	{
		if (*pArray == _iNum)
		{
			return false;
		}
		++pArray;
	}

	return true;
}

void Player(int* _pArray)
{
	int* pPlayer = _pArray;
	int iCount = 0;

	while (3 > iCount)
	{
		cout << iCount + 1 << "번째 숫자를 입력하시오. ";
		cin >> *pPlayer;

		if (9 < *pPlayer || 1 > *pPlayer)
		{
			cout << "잘못입력하셨습니다." << endl;
		}
		else
		{
			++pPlayer;
			++iCount;
		}
	}
	cout << endl;
}

bool GameCheak(const int* _pCom, const int* _pPlayer)
{
	int iStrike = 0;
	int iBall = 0;

	for (int i = 0; i < 3; ++i)
	{
		if (*_pCom == *_pPlayer)
		{
			iStrike++;
		}

		++_pCom;
		++_pPlayer;
	}

	_pCom -= 3;
	_pPlayer -= 3;

	if (iStrike != 3)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (*_pCom == *_pPlayer)
				{
					iBall++;
				}
				++_pPlayer;
			}
			_pPlayer -= 3;
			++_pCom;
		}

		iBall -= iStrike;
	}

	cout << iStrike << "스트라이크 " << iBall << "볼 " << endl;

	if (iStrike == 3)
	{
		cout << "승리하셨습니다." << endl;
		return true;
	}
	else
	{
		return false;
	}
}