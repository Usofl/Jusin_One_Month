#include <iostream>
#include <ctime>

using namespace std;

void main()
{
	// Ȧ¦ ���� (������ �̾Ƽ� �� ���ڰ� Ȧ���� ¦���� �Ǻ�, ������ 1~10���� �� �ϳ��� ����, 1. Ȧ�� 2. ¦�� 3. ����
	// �� 5���� �ǽ� ���� ����� �� �� �� �и� ��� �� ���帶�� ������ ���� ����
	int iChoice = 0, iNum = 0, iWin = 0, iLose = 0, iRound = 0;

	while (5 > iRound)
	{
		system("cls");
		cout << "���� " << iRound + 1 << endl;
		cout << "=========================================" << endl;

		srand(unsigned(time(NULL)));

		iNum = rand() % 10;

		cout << iNum << endl;
		cout << "1. Ȧ��\t2. ¦��\t3. ����" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (1 == iNum % 2)
			{
				iWin++;
				//				cout << "�¸�" << endl;
			}
			else
			{
				iLose++;
				//				cout << "�й�" << endl;
			}
		}
		else if (2 == iChoice)
		{
			if (0 == iNum % 2)
			{
				iWin++;
				//				cout << "�¸�" << endl;
			}
			else
			{
				iLose++;
				//				cout << "�й�" << endl;
			}
		}
		else if (3 == iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			iRound--;
		}

		iRound++;
	}

	cout << iWin << "�� " << iLose << "�� �ϼ̽��ϴ�." << endl;
}