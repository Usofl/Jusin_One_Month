// 220406.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

