#include <iostream>

using namespace std;

void Vending();
void InsertCoin(int* _iMoney);
bool CheakMoney(int* _iMoney);
void Choice(int* _iMoney, int iChoice, bool* _pExit);

void main()
{
	// 자판기 구현하기 (소지금 입력받기, 현재 소지금을 '잔액'으로 표기하여 출력, 1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.반환,
	// 선택에 의해 구매 시 잔액은 바뀌어야함, 소지금이 부족할 경우 구매 불가능, 잔액이 부족합니다 출력, 4번을 누르면 잔액은 ~~입니다 출력)
	Vending();
}

void InsertCoin(int* _iMoney)
{
	cout << "얼마를 가지고 있습니까 : ";
	cin >> *_iMoney;
}

bool CheakMoney(int* _iMoney)
{
	system("cls");

	cout << "잔액 " << *_iMoney << endl;
	cout << "1.콜라(100원)\t2.사이다(200원)\t3.환타(300원)\t4.반환" << endl;
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
			cout << "콜라를 구입하셨습니다." << endl;
		}
		else
		{
			cout << "잔액이 부족합니다." << endl;
		}
	}
	else if (2 == iChoice)
	{
		if (200 <= *_iMoney)
		{
			*_iMoney -= 200;
			cout << "사이다를 구입하셨습니다." << endl;
		}
		else
		{
			cout << "잔액이 부족합니다." << endl;
		}
	}
	else if (3 == iChoice)
	{
		if (300 <= *_iMoney)
		{
			*_iMoney -= 300;
			cout << "환타를 구입하셨습니다." << endl;
		}
		else
		{
			cout << "잔액이 부족합니다." << endl;
		}
	}
	else if (4 == iChoice)
	{
		*_pExit = false;
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
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


	cout << "남은 잔액은 " << iMoney << "원 입니다." << endl;
}