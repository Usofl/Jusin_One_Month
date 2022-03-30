#include "stdafx.h"
#include "DoubleLinkedList.h"


CDoubleLinkedList::CDoubleLinkedList()
	: m_Front_Node(nullptr)
	, m_Back_Node(nullptr)
	, m_List_Size(0)
{
}


CDoubleLinkedList::~CDoubleLinkedList()
{
	Release();
}

void CDoubleLinkedList::Render()
{
	if (!(Empty()))
	{
		CNode* node = m_Front_Node;
		int count = 0;
		while (true)
		{
			cout << count++ << ". " << node->Get_Data() << endl;
			node = node->Get_Next_Node();

			if (node == m_Back_Node)
			{
				cout << count++ << ". " << node->Get_Data() << endl;
				break;
			}
		}
	}
}

void CDoubleLinkedList::Reverse_Render()
{
	if (!(Empty()))
	{
		CNode* node = m_Back_Node;
		int count = m_List_Size - 1;
		while (true)
		{
			cout << count-- << ". " << node->Get_Data() << endl;
			node = node->Get_Pre_Node();

			if (node == m_Front_Node)
			{
				cout << count-- << ". " << node->Get_Data() << endl;
				break;
			}
		}
	}
}

void CDoubleLinkedList::Push(const int & _data)
{
	CNode* New_Node = new CNode(_data);

	if (0 == m_List_Size)
	{
		m_Front_Node = New_Node;
		m_Back_Node = New_Node;
	}

	++m_List_Size;

	m_Back_Node->Set_Next_Node(New_Node);
	New_Node->Set_Pre_Node(m_Back_Node);

	m_Back_Node = New_Node;
}

void CDoubleLinkedList::Insert_By_Index(const unsigned int & _index, const int & _data)
{
	CNode* Pre_Node = Search_Node_By_Index(_index);

	if (nullptr == Pre_Node)
	{
		return;
	}

	CNode* New_Node = new CNode(_data);
	++m_List_Size;

	if (Pre_Node == m_Front_Node)
	{
		m_Front_Node = New_Node;
		m_Front_Node->Set_Next_Node(Pre_Node);
		m_Front_Node->Set_Pre_Node(nullptr);
		
		Pre_Node->Set_Pre_Node(m_Front_Node);

		return;
	}

	Pre_Node->Get_Pre_Node()->Set_Next_Node(New_Node);

	New_Node->Set_Next_Node(Pre_Node);
	New_Node->Set_Pre_Node(Pre_Node->Get_Pre_Node());

	Pre_Node->Set_Pre_Node(New_Node);
}

void CDoubleLinkedList::Insert_By_Value(const int & _value, const int & _data)
{
	CNode* Pre_Node = Search_Node_By_Value(_value);

	if (nullptr == Pre_Node)
	{
		return;
	}

	CNode* New_Node = new CNode(_data);
	++m_List_Size;

	if (Pre_Node == m_Front_Node)
	{
		m_Front_Node = New_Node;
		m_Front_Node->Set_Next_Node(Pre_Node);
		m_Front_Node->Set_Pre_Node(nullptr);
		return;
	}
	Pre_Node->Get_Next_Node()->Set_Pre_Node(New_Node);

	New_Node->Set_Next_Node(Pre_Node->Get_Next_Node());
	New_Node->Set_Pre_Node(Pre_Node);

	Pre_Node->Set_Next_Node(New_Node);
}

void CDoubleLinkedList::Delete_By_Index(const unsigned int & _index)
{
	CNode* Delete_Node = Search_Node_By_Index(_index);

	if (nullptr == Delete_Node)
	{
		return;
	}

	--m_List_Size;

	if (Delete_Node == m_Front_Node)
	{
		m_Front_Node = m_Front_Node->Get_Next_Node();
		m_Front_Node->Set_Pre_Node(m_Front_Node);
		delete Delete_Node;
		return;
	}
	else if (Delete_Node == m_Back_Node)
	{
		m_Back_Node = m_Back_Node->Get_Pre_Node();
		m_Back_Node->Set_Next_Node(m_Back_Node);
		delete Delete_Node;
		return;
	}

	Delete_Node->Get_Pre_Node()->Set_Next_Node(Delete_Node->Get_Next_Node());
	Delete_Node->Get_Next_Node()->Set_Pre_Node(Delete_Node->Get_Pre_Node());
	delete Delete_Node;
}

void CDoubleLinkedList::Delete_By_Value(const int & _value)
{
	CNode* Delete_Node = Search_Node_By_Value(_value);

	if (nullptr == Delete_Node)
	{
		return;
	}

	--m_List_Size;

	if (Delete_Node == m_Front_Node)
	{
		m_Front_Node = m_Front_Node->Get_Next_Node();
		m_Front_Node->Set_Pre_Node(m_Front_Node);
		delete Delete_Node;
		return;
	}
	else if (Delete_Node == m_Back_Node)
	{
		m_Back_Node = m_Back_Node->Get_Pre_Node();
		m_Back_Node->Set_Next_Node(m_Back_Node);
		delete Delete_Node;
		return;
	}

	Delete_Node->Get_Pre_Node()->Set_Next_Node(Delete_Node->Get_Next_Node());
	Delete_Node->Get_Next_Node()->Set_Pre_Node(Delete_Node->Get_Pre_Node());
	delete Delete_Node;
}

const int & CDoubleLinkedList::Search_Value_By_Index(const unsigned int & _index)
{
	CNode* node = Search_Node_By_Index(_index);

	return node->Get_Data();
}

CNode * CDoubleLinkedList::Search_Node_By_Index(const unsigned int & _index)
{
	if (_index >= m_List_Size)
	{
		return nullptr;
	}
	else if (_index == m_List_Size - 1)
	{
		return m_Back_Node;
	}

	CNode* node = m_Front_Node;
	int count = 0;

	while (true)
	{
		if (_index == count++)
		{
			break;
		}

		node = node->Get_Next_Node();
	}

	return node;
}

CNode * CDoubleLinkedList::Search_Node_By_Value(const int & _value)
{
	if (Empty())
	{
		return nullptr;
	}

	CNode* node = m_Front_Node;

	while (true)
	{
		if (_value == node->Get_Data())
		{
			break;
		}
		else if (node == m_Back_Node)
		{
			return nullptr;
		}
		node = node->Get_Next_Node();
	}

	return node;
}

const size_t & CDoubleLinkedList::Get_size()
{
	return m_List_Size;
}

bool CDoubleLinkedList::Empty()
{
	return (0 >= m_List_Size);
}

void CDoubleLinkedList::Release()
{
	while (!(Empty()))
	{
		Delete_By_Index(0);
	}
}
