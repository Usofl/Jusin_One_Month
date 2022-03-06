#include <iostream>

using namespace std;

void main()
{
	// 국,영,수 점수 입력받고 출력
	// 분기문을 이용하여 평균 점수에 따라 성적 등급을 매긴다.

	// 90이상 100이하 a .... b, c, d, f

	int iKuk, iEng, iMath, iSum = 0;
	double dAvg = 0;

	while (1)
	{
		cout << "국어 점수를 입력하시오 : ";

		cin >> iKuk;

		if (100 < iKuk || 0 > iKuk)
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			iSum += iKuk;
			break;
		}
	}

	while (1)
	{
		cout << "영어 점수를 입력하시오 : ";

		cin >> iEng;

		if (100 < iEng || 0 > iEng)
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			iSum += iEng;
			break;
		}
	}

	while (1)
	{
		cout << "수학 점수를 입력하시오 : ";

		cin >> iMath;

		if (100 < iMath || 0 > iMath)
		{
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			iSum += iMath;
			break;
		}
	}

	dAvg = iSum / 3.0;

	cout << "국어 : " << iKuk << " | 영어 : " << iEng << " | 수학 : " << iMath << endl;

	cout << "총점 : " << iSum << " | 평균 : " << dAvg << endl;

	//===================================================================================

	if (90 <= dAvg && 100 >= dAvg)
	{
		cout << "등급 : " << "A" << endl;
	}
	else if (80 <= dAvg && 90 > dAvg)
	{
		cout << "등급 : " << "B" << endl;
	}
	else if (70 <= dAvg && 80 > dAvg)
	{
		cout << "등급 : " << "C" << endl;
	}
	else if (60 <= dAvg && 70 > dAvg)
	{
		cout << "등급 : " << "D" << endl;
	}
	else
	{
		cout << "등급 : " << "F" << endl;
	}

	//===================================================================================

	switch ((int)dAvg / 10)
	{
	case 10:
		cout << "등급 : " << "A" << endl;
		break;
	case 9:
		cout << "등급 : " << "A" << endl;
		break;
	case 8:
		cout << "등급 : " << "B" << endl;
		break;
	case 7:
		cout << "등급 : " << "C" << endl;
		break;
	case 6:
		cout << "등급 : " << "D" << endl;
		break;
	default:
		cout << "등급 : " << "F" << endl;
		break;
	}
}