#include <iostream>

using namespace std;

void Vending();
void InsertCoin(int* _iMoney);
bool CheakMoney(int* _iMoney);
void Choice(int* _iMoney, int iChoice, bool* _pExit);

void main()
{
	// ���Ǳ� �����ϱ� (������ �Է¹ޱ�, ���� �������� '�ܾ�'���� ǥ���Ͽ� ���, 1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.��ȯ,
	// ���ÿ� ���� ���� �� �ܾ��� �ٲ�����, �������� ������ ��� ���� �Ұ���, �ܾ��� �����մϴ� ���, 4���� ������ �ܾ��� ~~�Դϴ� ���)
	Vending();
}

void InsertCoin(int* _iMoney)
{
	cout << "�󸶸� ������ �ֽ��ϱ� : ";
	cin >> *_iMoney;
}

bool CheakMoney(int* _iMoney)
{
	system("cls");

	cout << "�ܾ� " << *_iMoney << endl;
	cout << "1.�ݶ�(100��)\t2.���̴�(200��)\t3.ȯŸ(300��)\t4.��ȯ" << endl;
	cout << "=========================================" << endl;

	if (100 > *_iMoney)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Choice(int* _iMoney, int iChoice, bool* _pExit)
{
	if (1 == iChoice)
	{
		if (100 <= *_iMoney)
		{
			*_iMoney -= 100;
			cout << "�ݶ� �����ϼ̽��ϴ�." << endl;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
		}
	}
	else if (2 == iChoice)
	{
		if (200 <= *_iMoney)
		{
			*_iMoney -= 200;
			cout << "���̴ٸ� �����ϼ̽��ϴ�." << endl;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
		}
	}
	else if (3 == iChoice)
	{
		if (300 <= *_iMoney)
		{
			*_iMoney -= 300;
			cout << "ȯŸ�� �����ϼ̽��ϴ�." << endl;
		}
		else
		{
			cout << "�ܾ��� �����մϴ�." << endl;
		}
	}
	else if (4 == iChoice)
	{
		*_pExit = false;
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
}

void Vending()
{
	int iMoney = 0;
	int iChoice = 0;
	bool bExit = true;

	InsertCoin(&iMoney);

	while (CheakMoney(&iMoney) && bExit)
	{
		cin >> iChoice;

		Choice(&iMoney, iChoice, &bExit);

		system("pause");
	}


	cout << "���� �ܾ��� " << iMoney << "�� �Դϴ�." << endl;
}