// 220401_LinkedList(T).cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	cout << "4�� �ε����� 77 ����" << endl;
	my_int_list.Insert_By_Index(4, 77);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "7�� �ε��� ����" << endl;
	my_int_list.Delete_By_Index(7);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "6�� �ε��� ����" << endl;
	my_int_list.Delete_By_Index(6);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "3�� �ε��� ����" << endl;
	my_int_list.Delete_By_Index(3);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "��77 ������ 56 ����" << endl;
	my_int_list.Insert_By_Value(77, 56);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "��35 ����" << endl;
	my_int_list.Delete_By_Value(35);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	cout << endl;
	cout << "��35 ����" << endl;
	my_int_list.Delete_By_Value(35);

	cout << "���� ������ : " << my_int_list.Get_Size() << endl;
	my_int_list.Render();

	my_int_list.Release();

	return 0;
}