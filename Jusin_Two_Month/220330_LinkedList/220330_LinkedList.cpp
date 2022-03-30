// 220330_LinkedList.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "LinkedList.h"

int main()
{
	CLinkedList my_list;

	my_list.Push(56);
	my_list.Push(35);
	my_list.Push(78);
	my_list.Push(21);
	my_list.Push(8);
	my_list.Push(97);
	my_list.Push(16);

	my_list.Render();
	
	cout << endl;
	cout << "4�� �ε����� 77 ����" << endl;
	my_list.Insert_By_Index(4, 77);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "7�� �ε��� ����" << endl;
	my_list.Delete_By_Index(7);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "6�� �ε��� ����" << endl;
	my_list.Delete_By_Index(6);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "3�� �ε��� ����" << endl;
	my_list.Delete_By_Index(3);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "��77 ������ 56 ����" << endl;
	my_list.Insert_By_Value(77, 56);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "��35 ����" << endl;
	my_list.Delete_By_Value(35);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	cout << endl;
	cout << "��35 ����" << endl;
	my_list.Delete_By_Value(35);

	cout << "���� ������ : " << my_list.Get_size() << endl;
	my_list.Render();

	my_list.Release();

    return 0;
}

