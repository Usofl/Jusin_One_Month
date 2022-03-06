#include <iostream>

using namespace std;

int GetTextLen(char* pText);
void ReverseText(char* pText);

void main()
{
	// 2. 문자열을 입력받고 null문자를 제외한 순수 문자열의 길이를 구하는 함수를 만들어라(strlen 금지)

	// 3. 입력 받은 문자열을 뒤집는 함수 만들기

	char cText[100] = {};

	cout << "문자를 입력하세요 (1 ~ 100자 이내)" << endl;
	cin >> cText;

	cout << "문자열의 길이는" << GetTextLen(cText) << "입니다." << endl;

	cout << "뒤집은 문자열은";

	ReverseText(cText);

	cout << " 입니다." << endl;
}

int GetTextLen(char* pText)
{
	int iLen = 0;

	for (int i = 0; '\0' != pText[i]; ++i)
	{
		iLen++;
	}

	return iLen;
}

void ReverseText(char* pText)
{
	const int iLen = GetTextLen(pText);

	for (int i = iLen; i >= 0; --i)
	{
		cout << pText[i];
	}
}