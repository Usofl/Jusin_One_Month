// 220401_SmartQueue(T).cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SmartQueue.h"

int main()
{
	CSmartQueue<int> my_int_Queue;
	CSmartQueue<double> my_double_Queue;

	my_int_Queue.Enqueue(9);
	my_int_Queue.Enqueue(68);
	my_int_Queue.Enqueue(22);
	my_int_Queue.Enqueue(19);
	my_int_Queue.Enqueue(37);
	my_int_Queue.Enqueue(49);
	my_int_Queue.Enqueue(15);
	my_int_Queue.Enqueue(2);

	my_double_Queue.Enqueue(5.5);
	my_double_Queue.Enqueue(15.97);
	my_double_Queue.Enqueue(8.87);
	my_double_Queue.Enqueue(94.354);
	my_double_Queue.Enqueue(67.346);
	my_double_Queue.Enqueue(26.19);
	my_double_Queue.Enqueue(88.14);

	cout << "Queue 사이즈 :" << my_int_Queue.Get_Size() << " " << my_int_Queue.Back() << " " << my_int_Queue.Front() << endl;
	cout << "Queue 사이즈 :" << my_double_Queue.Get_Size() << " " << my_double_Queue.Back() << " " << my_double_Queue.Front() << endl;

	while (!(my_int_Queue.Empty()))
	{
		cout << my_int_Queue.Get_Size() << ". " << my_int_Queue.Dequeue() << endl;
	}
	while (!(my_double_Queue.Empty()))
	{
		cout << my_double_Queue.Get_Size() << ". " << my_double_Queue.Dequeue() << endl;
	}

	my_int_Queue.Enqueue(9);
	my_int_Queue.Enqueue(68);
	my_int_Queue.Enqueue(22);
	my_int_Queue.Enqueue(19);
	my_int_Queue.Enqueue(37);
	my_int_Queue.Enqueue(49);
	my_int_Queue.Enqueue(15);
	my_int_Queue.Enqueue(2);

	my_int_Queue.Release();
    return 0;
}

