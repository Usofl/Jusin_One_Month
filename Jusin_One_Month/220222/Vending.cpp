#include <iostream>

using namespace std;

void main()
{
	// ���Ǳ� �����ϱ� (������ �Է¹ޱ�, ���� �������� '�ܾ�'���� ǥ���Ͽ� ���, 1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.��ȯ,
	// ���ÿ� ���� ���� �� �ܾ��� �ٲ�����, �������� ������ ��� ���� �Ұ���, �ܾ��� �����մϴ� ���, 4���� ������ �ܾ��� ~~�Դϴ� ���)
	int iMoney = 0, iChoice = 0;

	cout << "�󸶸� ������ �ֽ��ϱ� : ";
	cin >> iMoney;

	cout << "1.�ݶ�(100��)\t2.���̴�(200��)\t3.ȯŸ(300��)\t4.��ȯ" << endl;
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
				cout << "�ݶ� �����ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
			}
		}
		else if (2 == iChoice)
		{
			if (200 <= iMoney)
			{
				iMoney -= 200;
				cout << "���̴ٸ� �����ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
			}
		}
		else if (3 == iChoice)
		{
			if (300 <= iMoney)
			{
				iMoney -= 300;
				cout << "ȯŸ�� �����ϼ̽��ϴ�." << endl;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << endl;
			}
		}
		else if (4 == iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		cout << "���� �ܾ��� " << iMoney << "�� �Դϴ�." << endl;
	}

	cout << "���� �ܾ��� " << iMoney << "�� �Դϴ�." << endl;

}