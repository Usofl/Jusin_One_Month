#include <iostream>

using namespace std;

int GetTextLen(char* pText);
void ReverseText(char* pText);

void main()
{
	// 2. ���ڿ��� �Է¹ް� null���ڸ� ������ ���� ���ڿ��� ���̸� ���ϴ� �Լ��� ������(strlen ����)

	// 3. �Է� ���� ���ڿ��� ������ �Լ� �����

	char cText[100] = {};

	cout << "���ڸ� �Է��ϼ��� (1 ~ 100�� �̳�)" << endl;
	cin >> cText;

	cout << "���ڿ��� ���̴�" << GetTextLen(cText) << "�Դϴ�." << endl;

	cout << "������ ���ڿ���";

	ReverseText(cText);

	cout << " �Դϴ�." << endl;
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