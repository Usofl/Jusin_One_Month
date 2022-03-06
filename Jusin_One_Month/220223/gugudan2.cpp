#include <iostream>

using namespace std;

void main()
{
	// 2. for문을 이용해 구구단 2~9단 출력
	// 2-1. for문을 이용해 단과 곱을 입력받아 구구단 출력
	// ex) 5단 4곱 -> 2 * 1 = 2 ~ 2 * 4 = 8 ~ 5 * 4 = 20

	for (int i = 2; i < 10; ++i)
	{
		cout << i << "단" << endl;
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "==================================" << endl;
	}

	int iDan = 0, iGob = 0;

	cout << "몇단을 출력하시겠습니까?" << endl;
	cin >> iDan;

	cout << "몇곱을 출력하시겠습니까?" << endl;
	cin >> iGob;

	for (int i = 2; i <= iDan; ++i)
	{
		cout << i << "단" << endl;
		for (int j = 1; j <= iGob; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "==================================" << endl;
	}
}