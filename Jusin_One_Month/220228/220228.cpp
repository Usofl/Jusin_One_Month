#include <iostream>

using namespace std;

void swap(int* _iA, int* _iB);

void main()
{
	// iA, iB SWAP 함수만들기
	int iA = 10, iB = 20;

	cout << "iA : " << iA << "iB : " << iB << endl;

	swap(&iA, &iB);

	cout << "iA : " << iA << "iB : " << iB << endl;
}

void swap(int* _iA, int* _iB)
{
	int iTemp = *_iA;
	*_iA = *_iB;
	*_iB = iTemp;
}