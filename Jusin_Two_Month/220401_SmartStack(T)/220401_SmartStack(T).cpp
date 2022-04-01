// 220401_SmartStack(T).cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SmartStack.h"


int main()
{
	CSmartStack<int> my_int_stack;
	CSmartStack<double> my_double_stack;

	my_int_stack.Push(5);
	my_int_stack.Push(15);
	my_int_stack.Push(8);
	my_int_stack.Push(94);
	my_int_stack.Push(67);
	my_int_stack.Push(26);
	my_int_stack.Push(88);


	my_double_stack.Push(5.5);
	my_double_stack.Push(15.97);
	my_double_stack.Push(8.87);
	my_double_stack.Push(94.354);
	my_double_stack.Push(67.346);
	my_double_stack.Push(26.19);
	my_double_stack.Push(88.14);

	cout << my_int_stack.Get_Size() << ". " << my_int_stack.Top() << endl;
	cout << my_double_stack.Get_Size() << ". " << my_double_stack.Top() << endl;

	while (!(my_int_stack.Empty()))
	{
		cout << my_int_stack.Get_Size() << ". " << my_int_stack.Pop() << endl;
	}

	while (!(my_double_stack.Empty()))
	{
		cout << my_double_stack.Get_Size() << ". " << my_double_stack.Pop() << endl;
	}

	my_int_stack.Push(5);
	my_int_stack.Push(15);
	my_int_stack.Push(8);
	my_int_stack.Push(94);
	my_int_stack.Push(67);
	my_int_stack.Push(26);
	my_int_stack.Push(88);

	my_double_stack.Push(5.5);
	my_double_stack.Push(15.97);
	my_double_stack.Push(8.87);
	my_double_stack.Push(94.354);
	my_double_stack.Push(67.346);
	my_double_stack.Push(26.19);
	my_double_stack.Push(88.14);

	my_int_stack.Release();
	my_double_stack.Release();

	return 0;
}

