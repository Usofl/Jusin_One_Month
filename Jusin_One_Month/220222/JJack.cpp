#include <iostream>

using namespace std;

void main()
{
	// do while���� �̿��� ���ڸ� �Է¹ް� ¦���� ��쿡�� ���� ���ϴ� ���α׷� ����� (5��)

	int iCount = 5, iSum = 0, iNum = 0;

	do
	{
		system("cls");
		cout << 6 - iCount << "��° ���� �Է��Ͻÿ� : ";
		cin >> iNum;

		if (0 == iNum % 2)
		{
			iSum += iNum;
		}

		iCount--;

	} while (0 < iCount);

	cout << "�Է��� �� ��� ¦���� ���� " << iSum << "�Դϴ�." << endl;
}