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
	// �߱�����
	// 1~9������ ������ ���� 3���� ����
	// ���� x
	// �Է��ϴ� ���ڿ� ������ ������ ���� �ڸ��� ��ġ�ϸ� ��Ʈ����ũ, ���� ��ġ�ϸ� ��
	// ��ȸ �Է� �� �� ��Ʈ����ũ �� �� ���
	// 9���� ����, 3��Ʈ����ũ�� ������� �й�

	int iCom[3] = {};
	int iPlayer[3] = {};
	int iRound = 0;

	Draw(iCom);


	cout << "��ǻ���� ���ڴ� ( ";
	for (int i = 0; i < 3; ++i)
	{
		cout << iCom[i] << " ";
	}
	cout << ") �Դϴ�." << endl;

	while (9 > iRound)
	{
		Player(iPlayer);

		cout << iRound + 1 << "��° ���� ";

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
		cout << iCount + 1 << "��° ���ڸ� �Է��Ͻÿ�. ";
		cin >> *pPlayer;

		if (9 < *pPlayer || 1 > *pPlayer)
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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

	cout << iStrike << "��Ʈ����ũ " << iBall << "�� " << endl;

	if (iStrike == 3)
	{
		cout << "�¸��ϼ̽��ϴ�." << endl;
		return true;
	}
	else
	{
		return false;
	}
}