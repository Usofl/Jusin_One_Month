#include <iostream>

using namespace std;

void main()
{
	// 국,영,수 점수 입력받고 출력

	int iKuk, iEng, iMath = 0;

	cout << "국어 점수를 입력하시오 : ";

	cin >> iKuk;

	cout << "영어 점수를 입력하시오 : ";

	cin >> iEng;

	cout << "수학 점수를 입력하시오 : ";

	cin >> iMath;

	cout << "국어 : " << iKuk << " | 영어 : " << iEng << " | 수학 : " << iMath << endl;
}