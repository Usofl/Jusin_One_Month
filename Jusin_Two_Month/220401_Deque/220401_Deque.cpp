// 220401_Deque.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Deque.h"


int main()
{
	CDeque<int> my_int_deque;

	my_int_deque.Push_Front(5);
	my_int_deque.Push_Back(15);
	my_int_deque.Push_Front(8);
	my_int_deque.Push_Front(94);
	my_int_deque.Push_Back(67);
	my_int_deque.Push_Front(26);
	my_int_deque.Push_Back(88);

	cout << my_int_deque.Get_Size() << ". " << my_int_deque.Front() << endl;
	cout << my_int_deque.Get_Size() << ". " << my_int_deque.Back() << endl;

	while (!(my_int_deque.Empty()))
	{
		cout << my_int_deque.Get_Size() << ". " << my_int_deque.Pop_Front() << endl;
	}

	my_int_deque.Push_Front(5);
	my_int_deque.Push_Back(15);
	my_int_deque.Push_Front(8);
	my_int_deque.Push_Front(94);
	my_int_deque.Push_Back(67);
	my_int_deque.Push_Front(26);
	my_int_deque.Push_Back(88);

	while (!(my_int_deque.Empty()))
	{
		cout << my_int_deque.Get_Size() << ". " << my_int_deque.Pop_Back() << endl;
	}

	my_int_deque.Release();

	return 0;
}

