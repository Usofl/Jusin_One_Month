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
	// �ζ� �����
	// - �迭�� �̿��Ͽ� 1 ~ 45������ ���� �������� 6�� ���ڸ� 5ȸ ���
	// - ���� ȸ�������� ���� �ߺ� ��ȣ�� ���� �� ����, �������� ����(���� ����)
	int LottoNum[6] = {};

	Draw(LottoNum);
	bubble_solt(LottoNum);

	cout << "������ ��÷ ��ȣ�� ( ";

	for (int i = 0; i < 6; ++i)
	{
		cout << LottoNum[i] << " ";
	}

	cout << ") �Դϴ�." << endl;
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