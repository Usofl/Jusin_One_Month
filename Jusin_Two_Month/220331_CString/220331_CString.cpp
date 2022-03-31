// 220331_CString.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	CMyString Str("김수영");

	CMyString Str2("쥬신게임아카데미");

	cout << Str.Get_Str_Size() << Str << endl;
	cout << Str2.Get_Str_Size() << Str2 + Str << endl;

	CMyString Str3 = Str2;

	cout << Str2.Get_Str_Size() << Str2 << endl;
	cout << Str2.Get_Str_Size() << Str3 << endl;

	if (Str3 == Str2)
	{
		cout << "일치" << endl;
	}
	else
	{
		cout << "불일치" << endl;
	}

	if (Str3 == Str)
	{
		cout << "일치" << endl;
	}
	else
	{
		cout << "불일치" << endl;
	}

	return 0;
}