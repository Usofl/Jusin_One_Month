#include <iostream>

using namespace std;

void main()
{
	// while���� �̿��� 2~9�ܱ��� �ϼ��ϱ�

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