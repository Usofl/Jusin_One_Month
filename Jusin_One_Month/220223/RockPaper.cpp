#include <iostream>
#include <ctime>

using namespace std;

int computer();
int game(int _iChoice, int _iCom);
void trans(int _iCom);

void main()
{
	// 1. ���������� ���� 
	// 0~2���� �� �ϳ��� ����. (1. ���� 2. ���� 3. �� 4. ����)
	// �Է��� ���� ������ ���ؼ� ���������� ��, ��, �и� �Ǻ�
	// 5���� ����� �� �� �� ��� (����)

	int iCom = 0, iPlayer = 0, iRound = 0, iWin = 0, iDraw = 0;
	bool bExit = true;

	while (bExit)
	{
		if (iRound == 5)
		{
			break;
		}

		system("cls");
		cout << "���� " << iRound + 1 << endl;
		cout << "=========================================" << endl;

		iCom = computer();

		trans(iCom);

		cout << "1. ����\t2. ����\t3. ��\t4. ����" << endl;
		cin >> iPlayer;

		switch (game(iPlayer, iCom))
		{
		case 1:
			iWin++;
			cout << "�¸�" << endl;
			break;
		case 2:
			cout << "�й�" << endl;
			break;
		case 3:
			iDraw++;
			cout << "���º�" << endl;
			break;
		case 4:
			bExit = false;
			break;
		default:
			iRound--;
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			break;
		}

		iRound++;

		system("pause");
	}

	cout << iWin << "�� " << iDraw << "�� " << (iRound - iWin - iDraw) << "�� �ϼ̽��ϴ�." << endl;
}

int computer()
{
	srand(unsigned(time(NULL)));

	return rand() % 3 + 1;
}

int game(int _iChoice, int _iCom)
{
	int iNum = 0;

	if (_iChoice == _iCom)
	{
		iNum = 3;
		return iNum;
	}

	if (1 == _iChoice)
	{
		if (3 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (2 == _iChoice)
	{
		if (1 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (3 == _iChoice)
	{
		if (2 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (4 == _iChoice)
	{
		iNum = 4;
	}

	return iNum;
}

void trans(int _iCom)
{
	if (1 == _iCom)
	{
		cout << "����" << endl;
	}
	else if (2 == _iCom)
	{
		cout << "����" << endl;
	}
	else if (3 == _iCom)
	{
		cout << "��" << endl;
	}
}