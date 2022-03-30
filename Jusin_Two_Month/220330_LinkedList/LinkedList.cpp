#include "stdafx.h"
#include "LinkedList.h"

CLinkedList::CLinkedList()
	: m_Front_Node(nullptr)
	, m_Back_Node(nullptr)
	, m_List_Size(0)
{
}

CLinkedList::~CLinkedList()
{
}

void CLinkedList::Render()
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

void CLinkedList::Push(const int & _data)
{
	CNode* New_Node = new CNode(_data);

	if (nullptr == m_Front_Node)
	{
		m_Front_Node = New_Node;
		m_Back_Node = New_Node;
	}

	m_Back_Node->Set_Next_Node(New_Node);
	m_Back_Node = New_Node;

	++m_List_Size;
}

void CLinkedList::Insert_By_Index(const unsigned int & _index, const int & _data)
{
	if (_index > m_List_Size)
	{
		cout << "초과한 인덱스 입니다." << endl;
		return;
	}

	CNode* New_Node = new CNode(_data);
	
	++m_List_Size;
	
	if (0 == _index)
	{
		New_Node->Set_Next_Node(m_Front_Node);
		m_Front_Node = New_Node;
		return;
	}
	CNode* Pre_Node = Search_Node_By_Index(_index - 1);

	New_Node->Set_Next_Node(Pre_Node->Get_Next_Node());
	Pre_Node->Set_Next_Node(New_Node);
}

void CLinkedList::Insert_By_Value(const int & _value, const int & _data)
{
	CNode* Pre_Node = Search_Node_By_Value(_value);
	if (nullptr == Pre_Node)
	{
		cout << "입력한 값은 리스트에 없습니다." << endl;
		return;
	}

	CNode* New_Node = new CNode(_data);

	++m_List_Size;

	New_Node->Set_Next_Node(Pre_Node->Get_Next_Node());
	Pre_Node->Set_Next_Node(New_Node);
}

void CLinkedList::Delete_By_Index(const unsigned int & _index)
{
	if (_index >= m_List_Size)
	{
		return;
	}

	CNode* node = nullptr;
	
	--m_List_Size;

	if (0 == _index)
	{
		node = m_Front_Node;

		m_Front_Node = m_Front_Node->Get_Next_Node();
		delete node;

		return;
	}
	node = Search_Node_By_Index(_index - 1);
	CNode* delete_Node = node->Get_Next_Node();

	if (m_Back_Node == delete_Node)
	{
		delete delete_Node;
		m_Back_Node = node;

		return;
	}

	node->Set_Next_Node(delete_Node->Get_Next_Node());
	delete delete_Node;
}

void CLinkedList::Delete_By_Value(const int & _value)
{
	if (Empty())
	{
		return;
	}

	CNode* node = m_Front_Node;

	if (_value == node->Get_Data())
	{
		m_Front_Node = node->Get_Next_Node();
		--m_List_Size;
		delete node;

		return;
	}

	while (true)
	{
		if (_value == node->Get_Next_Node()->Get_Data())
		{
			CNode* delete_Node = node->Get_Next_Node();

			if (m_Back_Node == delete_Node)
			{
				m_Back_Node = node;
			}

			node->Set_Next_Node(delete_Node->Get_Next_Node());
			delete delete_Node;
			--m_List_Size;
			return;
		}
		else if (m_Back_Node == node->Get_Next_Node())
		{
			return;
		}
		else
		{
			node = node->Get_Next_Node();
		}
	}
}

const int & CLinkedList::Search_Value_By_Index(const unsigned int & _index)
{
	CNode* node = Search_Node_By_Index(_index);

	return node->Get_Data();
}

CNode * CLinkedList::Search_Node_By_Index(const unsigned int & _index)
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
		if (_index == count)
		{
			break;
		}
		++count;
		node = node->Get_Next_Node();
	}

	return node;
}

CNode * CLinkedList::Search_Node_By_Value(const int & _value)
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
			return node;
		}
		else if(node == m_Back_Node)
		{
			return nullptr;
		}
		else
		{
			node = node->Get_Next_Node();
		}
	}
}

const size_t & CLinkedList::Get_size()
{
	return m_List_Size;
}

bool CLinkedList::Empty()
{
	return (0 == m_List_Size);
}

void CLinkedList::Release()
{
	while (!(Empty()))
	{
		Delete_By_Index(0);
	}
}
