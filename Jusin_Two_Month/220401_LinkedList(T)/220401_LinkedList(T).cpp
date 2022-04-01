// 220401_LinkedList(T).cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LinkedList.h"

int main()
{
	CLinkedList<int> my_int_list;

	my_int_list.Push(56);
	my_int_list.Push(35);
	my_int_list.Push(78);
	my_int_list.Push(21);
	my_int_list.Push(8);
	my_int_list.Push(97);
	my_int_list.Push(16);

	my_int_list.Render();

	cout << endl;
	cout << "4번 인덱스에 77 삽입" << endl;
	my_int_list.Insert_By_Index(4, 77);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "7번 인덱스 삭제" << endl;
	my_int_list.Delete_By_Index(7);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "6번 인덱스 삭제" << endl;
	my_int_list.Delete_By_Index(6);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "3번 인덱스 삭제" << endl;
	my_int_list.Delete_By_Index(3);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "값77 다음에 56 삽입" << endl;
	my_int_list.Insert_By_Value(77, 56);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "값35 삭제" << endl;
	my_int_list.Delete_By_Value(35);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "값35 삭제" << endl;
	my_int_list.Delete_By_Value(35);

	cout << "현제 사이즈 : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	my_int_list.Release();

	return 0;
}