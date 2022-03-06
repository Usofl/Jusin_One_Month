#include <iostream>

void Stars(int _iNum);

using namespace std;

void main()
{
	// 3.����ó�� ���� ����϶�
	// *
	// **
	// ***
	// ****
	// *****

	int iNum = 0;

	cout << "������ �Է��Ͻÿ�." << endl;
	cin >> iNum;

	Stars(iNum);
}

void Stars(int _iNum)
{
	cout << endl;

	for (int i = 0; i < _iNum; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "=============" << endl;

	// *****
	// ****
	// ***
	// **
	// *

	for (int i = 0; i < _iNum; ++i)
	{
		for (int j = _iNum; j > i; --j)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "=============" << endl;

	//     *
	//    **
	//   ***
	//  ****
	// *****

	for (int i = 0; i < _iNum; ++i)
	{
		for (int j = _iNum - 1; j >= 0; --j)
		{
			if (i >= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << "=============" << endl;

	// *****
	//  ****
	//   ***
	//    **
	//     *

	for (int i = 0; i < _iNum; ++i)
	{
		for (int j = 0; j < _iNum; ++j)
		{
			if (i > j)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << "=============" << endl;
}