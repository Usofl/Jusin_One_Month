#include <iostream>

using namespace std;

void main()
{
	// ��,��,�� ���� �Է¹ް� ���
	// �б⹮�� �̿��Ͽ� ��� ������ ���� ���� ����� �ű��.

	// 90�̻� 100���� a .... b, c, d, f

	int iKuk, iEng, iMath, iSum = 0;
	double dAvg = 0;

	while (1)
	{
		cout << "���� ������ �Է��Ͻÿ� : ";

		cin >> iKuk;

		if (100 < iKuk || 0 > iKuk)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else
		{
			iSum += iKuk;
			break;
		}
	}

	while (1)
	{
		cout << "���� ������ �Է��Ͻÿ� : ";

		cin >> iEng;

		if (100 < iEng || 0 > iEng)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else
		{
			iSum += iEng;
			break;
		}
	}

	while (1)
	{
		cout << "���� ������ �Է��Ͻÿ� : ";

		cin >> iMath;

		if (100 < iMath || 0 > iMath)
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else
		{
			iSum += iMath;
			break;
		}
	}

	dAvg = iSum / 3.0;

	cout << "���� : " << iKuk << " | ���� : " << iEng << " | ���� : " << iMath << endl;

	cout << "���� : " << iSum << " | ��� : " << dAvg << endl;

	//===================================================================================

	if (90 <= dAvg && 100 >= dAvg)
	{
		cout << "��� : " << "A" << endl;
	}
	else if (80 <= dAvg && 90 > dAvg)
	{
		cout << "��� : " << "B" << endl;
	}
	else if (70 <= dAvg && 80 > dAvg)
	{
		cout << "��� : " << "C" << endl;
	}
	else if (60 <= dAvg && 70 > dAvg)
	{
		cout << "��� : " << "D" << endl;
	}
	else
	{
		cout << "��� : " << "F" << endl;
	}

	//===================================================================================

	switch ((int)dAvg / 10)
	{
	case 10:
		cout << "��� : " << "A" << endl;
		break;
	case 9:
		cout << "��� : " << "A" << endl;
		break;
	case 8:
		cout << "��� : " << "B" << endl;
		break;
	case 7:
		cout << "��� : " << "C" << endl;
		break;
	case 6:
		cout << "��� : " << "D" << endl;
		break;
	default:
		cout << "��� : " << "F" << endl;
		break;
	}
}