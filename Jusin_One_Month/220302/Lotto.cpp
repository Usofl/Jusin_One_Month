#include <iostream>
#include <random>

using namespace std;

int randomNum();
void Draw(int* _pArray);
bool cheak(int* _pArray, int _iNum);
void bubble_solt(int* _pArray);
bool solt_check(int* _pArray);
void swap(int* _iA, int* _iB);

void main()
{
	// 로또 만들기
	// - 배열을 이용하여 1 ~ 45사이의 수중 무작위로 6개 숫자를 5회 출력
	// - 같은 회차에서는 절대 중복 번호가 나올 수 없음, 오름차순 정렬(버블 정렬)
	int LottoNum[6] = {};

	Draw(LottoNum);
	bubble_solt(LottoNum);

	cout << "오늘의 추첨 번호는 ( ";

	for (int i = 0; i < 6; ++i)
	{
		cout << LottoNum[i] << " ";
	}

	cout << ") 입니다." << endl;
}


int randomNum()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(1, 45);

	return dis(gen);
}

void Draw(int* _pArray)
{
	int* pArray = _pArray;
	int iNum = 0;
	int iCount = 0;

	while (6 > iCount)
	{
		iNum = randomNum();

		if (cheak(_pArray, iNum))
		{
			*pArray = iNum;
			pArray++;
			iCount++;
		}
	}
}

bool cheak(int* _pArray, int _iNum)
{
	int* pArray = _pArray;

	for (int i = 0; i < 6; ++i)
	{
		if (*pArray == _iNum)
		{
			return false;
		}
		++pArray;
	}

	return true;
}

void bubble_solt(int* _pArray)
{
	while (!solt_check(_pArray))
	{
		int* pArray = _pArray;

		for (int i = 0; i < 5; ++i)
		{
			if (*pArray > *(pArray + 1))
			{
				swap(pArray, pArray + 1);
			}
			++pArray;
		}
	}
}

bool solt_check(int* _pArray)
{
	int* pArray = _pArray;

	for (int i = 0; i < 5; ++i)
	{
		if (*pArray > *(pArray + 1))
		{
			return false;
		}
		pArray++;
	}
	return true;
}

void swap(int* _iA, int* _iB)
{
	int iTemp = *_iA;
	*_iA = *_iB;
	*_iB = iTemp;
}