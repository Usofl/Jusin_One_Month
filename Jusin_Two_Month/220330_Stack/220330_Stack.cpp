// 220330_Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SmartStack.h"


int main()
{
	CSmartStack my_stack;

	my_stack.Push(5);
	my_stack.Push(15);
	my_stack.Push(8);
	my_stack.Push(94);
	my_stack.Push(67);
	my_stack.Push(26);
	my_stack.Push(88);

	cout << my_stack.Get_Size() << ". " << my_stack.Top() << endl;

	while (!(my_stack.Empty()))
	{
		cout << my_stack.Get_Size() << ". " << my_stack.Pop() << endl;
	}

	my_stack.Push(5);
	my_stack.Push(15);
	my_stack.Push(8);
	my_stack.Push(94);
	my_stack.Push(67);
	my_stack.Push(26);
	my_stack.Push(88);

	my_stack.Release();

    return 0;
}

