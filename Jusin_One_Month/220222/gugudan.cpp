#include <iostream>

using namespace std;

void main()
{
	// while문을 이용해 2~9단까지 완성하기

	int i = 2, j = 1;

	while (10 > i)
	{
		cout << i << " * " << j << " = " << i * j << endl;
		j++;

		if (j == 10)
		{
			i++;
			j = 1;
			cout << "=========================================" << endl;
		}
	}
}