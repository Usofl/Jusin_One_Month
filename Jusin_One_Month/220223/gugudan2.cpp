#include <iostream>

using namespace std;

void main()
{
	// 2. for���� �̿��� ������ 2~9�� ���
	// 2-1. for���� �̿��� �ܰ� ���� �Է¹޾� ������ ���
	// ex) 5�� 4�� -> 2 * 1 = 2 ~ 2 * 4 = 8 ~ 5 * 4 = 20

	for (int i = 2; i < 10; ++i)
	{
		cout << i << "��" << endl;
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "==================================" << endl;
	}

	int iDan = 0, iGob = 0;

	cout << "����� ����Ͻðڽ��ϱ�?" << endl;
	cin >> iDan;

	cout << "����� ����Ͻðڽ��ϱ�?" << endl;
	cin >> iGob;

	for (int i = 2; i <= iDan; ++i)
	{
		cout << i << "��" << endl;
		for (int j = 1; j <= iGob; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "==================================" << endl;
	}
}