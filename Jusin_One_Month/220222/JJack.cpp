#include <iostream>

using namespace std;

void main()
{
	// do while문을 이용해 숫자를 입력받고 짝수의 경우에만 합을 구하는 프로그램 만들기 (5번)

	int iCount = 5, iSum = 0, iNum = 0;

	do
	{
		system("cls");
		cout << 6 - iCount << "번째 수를 입력하시오 : ";
		cin >> iNum;

		if (0 == iNum % 2)
		{
			iSum += iNum;
		}

		iCount--;

	} while (0 < iCount);

	cout << "입력한 수 가운데 짝수의 합은 " << iSum << "입니다." << endl;
}