#include <iostream>

using namespace std;

void main()
{
	// 10 ~ 20 ������
	// ������ ��� ���ϱ�
	// ��,��,�� ���� �Է¹ް� ���

	int iKuk, iEng, iMath, iSum = 0;

	double dAug = 0.0;

	cout << "���� ������ �Է��Ͻÿ� : ";

	cin >> iKuk;

	iSum += iKuk;

	cout << "���� ������ �Է��Ͻÿ� : ";

	cin >> iEng;

	iSum += iEng;

	cout << "���� ������ �Է��Ͻÿ� : ";

	cin >> iMath;

	iSum += iMath;

	cout << "���� : " << iKuk << " | ���� : " << iEng << " | ���� : " << iMath << endl;

	dAug = (double)iSum / 3;

	cout << "���� : " << iSum << " | ��� : " << dAug << endl;
}