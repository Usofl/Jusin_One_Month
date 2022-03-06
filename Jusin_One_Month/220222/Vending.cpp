#include <iostream>

using namespace std;

void main()
{
	// 자판기 구현하기 (소지금 입력받기, 현재 소지금을 '잔액'으로 표기하여 출력, 1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.반환,
	// 선택에 의해 구매 시 잔액은 바뀌어야함, 소지금이 부족할 경우 구매 불가능, 잔액이 부족합니다 출력, 4번을 누르면 잔액은 ~~입니다 출력)
	int iMoney = 0, iChoice = 0;

	cout << "얼마를 가지고 있습니까 : ";
	cin >> iMoney;

	cout << "1.콜라(100원)\t2.사이다(200원)\t3.환타(300원)\t4.반환" << endl;
	cout << "=========================================" << endl;

	while (true)
	{
		if (100 > iMoney)
		{
			break;
		}

		cin >> iChoice;

		if (1 == iChoice)
		{
			if (100 <= iMoney)
			{
				iMoney -= 100;
				cout << "콜라를 구입하셨습니다." << endl;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if (2 == iChoice)
		{
			if (200 <= iMoney)
			{
				iMoney -= 200;
				cout << "사이다를 구입하셨습니다." << endl;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if (3 == iChoice)
		{
			if (300 <= iMoney)
			{
				iMoney -= 300;
				cout << "환타를 구입하셨습니다." << endl;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
		}
		else if (4 == iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		cout << "남은 잔액은 " << iMoney << "원 입니다." << endl;
	}

	cout << "남은 잔액은 " << iMoney << "원 입니다." << endl;

}