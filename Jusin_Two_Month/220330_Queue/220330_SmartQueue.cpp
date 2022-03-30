// 220330_Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SmartQueue.h"

int main()
{
	CSmartQueue my_Queue;

	my_Queue.Enqueue(9);
	my_Queue.Enqueue(68);
	my_Queue.Enqueue(22);
	my_Queue.Enqueue(19);
	my_Queue.Enqueue(37);
	my_Queue.Enqueue(49);
	my_Queue.Enqueue(15);
	my_Queue.Enqueue(2);

	cout << "Queue 사이즈 :" << my_Queue.Get_Size() << endl;

	int i = 1;
	while (!(my_Queue.Empty()))
	{
		cout << i++ << ". " << my_Queue.Dequeue() << endl;
	}

	my_Queue.Enqueue(9);
	my_Queue.Enqueue(68);
	my_Queue.Enqueue(22);
	my_Queue.Enqueue(19);
	my_Queue.Enqueue(37);
	my_Queue.Enqueue(49);
	my_Queue.Enqueue(15);
	my_Queue.Enqueue(2);

	my_Queue.Release();

    return 0;
}

