#include <iostream>
#include <cmath>

using namespace std;

int Patorial(int i);
int Pibonachi(int i);
int sun(int i, int j);
int Com(int i, int j);
int Hanoi(int i);
int Xpow(int i, int j);
int sosu(int i, int j = -1);

int main()
{
	// 5 팩토리얼을 함수로 구현하라

	int i = 0;

	cout << "몇 팩토리얼을 출력하겠습니까? ";
	cin >> i;

	cout << Patorial(i) << endl;

	cout << "몇번째 피보나치 행렬을 출력하겠습니까? ";
	cin >> i;

	cout << Pibonachi(i) << endl;

	cout << sun(6, 3) << endl;

	cout << Com(7, 3) << endl;

	cout << Hanoi(5) << endl;

	cout << Xpow(5, 3) << endl;

	cout << sosu(100) << endl;

	return 0;
}

int Patorial(int i)
{
	if (i == 1)
	{
		return i;
	}

	return i * Patorial(i - 1);
}

int Pibonachi(int i)
{
	if (i <= 2)
	{
		return 1;
	}

	return Pibonachi(i - 1) + Pibonachi(i - 2);
}

int sun(int i, int j)
{
	if (i == 1 || j == 1)
	{
		return i;
	}

	return i * sun(i - 1, j - 1);
}

int Com(int i, int j)
{
	if (i == j)
	{
		return 1;
	}

	if (i <= 1 || j <= 1)
	{
		return i;
	}

	return Com(i - 1, j) + Com(i - 1, j - 1);
}

int Hanoi(int i)
{
	if (i == 1)
	{
		return 1;
	}

	return (2 * Hanoi(i - 1)) + 1;
}

int Xpow(int i, int j)
{
	if (j == 0)
	{
		return 1;
	}

	if (j == 1)
	{
		return i;
	}

	return i * Xpow(i, j - 1);
}

int sosu(int i, int j)
{
	if (j == 1)
	{
		return 1 + sosu(i - 1);
	}
	else if (j == -1)
	{
		j = (int)sqrt(i) + 1;
	}

	if (i == 2)
	{
		return 1;
	}

	if (!(i % j))
	{
		return 0 + sosu(i - 1);
	}
	else
	{
		return sosu(i, j - 1);
	}
}