#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

bool Yaksu(int iNum);
int solution(int left, int right);

void main()
{
	int s = solution(13, 17);

	cout << s << endl;
}

int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; ++i)
	{
		if (Yaksu(i))
		{
			answer += i;
		}
		else
		{
			answer -= i;
		}
	}

	return answer;
}

bool Yaksu(int iNum)
{
	int iCount = 0;

	for (int i = iNum; i > 0; --i)
	{
		if (iNum % i  == 0)
		{
			iCount++;
		}
	}

	if (iCount % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}