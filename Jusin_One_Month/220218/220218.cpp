#include <iostream>

using namespace std;

void main()
{
	// 10 ~ 20 이진수
	// 총점과 평균 구하기
	// 국,영,수 점수 입력받고 출력

	int iKuk, iEng, iMath, iSum = 0;

	double dAug = 0.0;

	cout << "국어 점수를 입력하시오 : ";

	cin >> iKuk;

	iSum += iKuk;

	cout << "영어 점수를 입력하시오 : ";

	cin >> iEng;

	iSum += iEng;

	cout << "수학 점수를 입력하시오 : ";

	cin >> iMath;

	iSum += iMath;

	cout << "국어 : " << iKuk << " | 영어 : " << iEng << " | 수학 : " << iMath << endl;

	dAug = (double)iSum / 3;

	cout << "총점 : " << iSum << " | 평균 : " << dAug << endl;
}