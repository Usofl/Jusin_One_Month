// 220406.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int main()
{
	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);
	vecInt.push_back(60);
	vecInt.push_back(70);

	auto iter = vecInt.begin();

	iter += 3;

	vecInt.insert(iter + 1, 220);

	cout << (*iter) << endl;

    return 0;
}

