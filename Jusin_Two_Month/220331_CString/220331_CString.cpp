// 220331_CString.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	CMyString Str("�����");

	CMyString Str2("��Ű��Ӿ�ī����");

	cout << Str.Get_Str_Size() << Str << endl;
	cout << Str2.Get_Str_Size() << Str2 + Str << endl;

	CMyString Str3;
	Str3 = Str2;

	cout << Str2.Get_Str_Size() << Str2 << endl;
	cout << Str2.Get_Str_Size() << Str3 << endl;

	if (Str3 == Str2)
	{
		cout << "��ġ" << endl;
	}
	else
	{
		cout << "����ġ" << endl;
	}

	Str = (Str + "������");
	cout << Str.Get_Str_Size() << Str << endl;
	Str = "�õ�";
	cout << Str.Get_Str_Size() << Str << endl;

	if (Str3 == Str)
	{
		cout << "��ġ" << endl;
	}
	else
	{
		cout << "����ġ" << endl;
	}

	return 0;
}