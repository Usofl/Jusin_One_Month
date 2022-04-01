#pragma once
#include "Node.h"

template<typename T>
class CLinkedList
{
public:

	void Render()
	{
		if (Empty())
		{
			return;
		}

		CNode<T>* node = m_Front_Node;
		int i = 0;

		while (m_Back_Node != node)
		{
			cout << ++i << ". " << node->Get_Data() << endl;
			node = node->Get_Next_Node();
		}

		cout << ++i << ". " << node->Get_Data() << endl;
	}

	void Push(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);
		if (Empty())
		{
			m_Front_Node = new_Node;
			m_Back_Node = new_Node;
		}

		m_Back_Node->Set_Next_Node(new_Node);
		m_Back_Node = new_Node;
		++m_List_Size;
	}

	void Insert_By_Index(const unsigned int& _index, const T& _data)
	{
		if (_index > m_List_Size)
		{
			return;
		}
		else if (_index == m_List_Size)
		{
			Push(_data);
			return;
		}

		CNode<T>* new_Node = new CNode<T>(_data);
		CNode<T>* pre_Node = Search_Node_By_Index(_index - 1);

		new_Node->Set_Next_Node(pre_Node->Get_Next_Node());
		pre_Node->Set_Next_Node(new_Node);
		++m_List_Size;
	}

	void Insert_By_Value(const T& _value, const T& _data)
	{
		CNode<T>* pre_Node = Search_Node_By_Value(_value);

		if (nullptr == pre_Node)
		{
			return;
		}

		CNode<T>* new_Node = new CNode<T>(_data);
		new_Node->Set_Next_Node(pre_Node->Get_Next_Node());
		pre_Node->Set_Next_Node(new_Node);
		++m_List_Size;

		if (pre_Node == m_Front_Node)
		{
			m_Front_Node = new_Node;
		}

		if (pre_Node == m_Back_Node)
		{
			m_Back_Node = new_Node;
		}
	}

	void Delete_By_Index(const unsigned int& _index)
	{
		if (Empty() || (_index > m_List_Size))
		{
			return;
		}

		CNode<T>* pre_Node = nullptr;
		CNode<T>* delete_Node = nullptr;

		if (_index == 0)
		{
			--m_List_Size;
			delete_Node = m_Front_Node;
			m_Front_Node = m_Front_Node->Get_Next_Node();
			SAFE_DELETE(delete_Node);
			return;
		}

		pre_Node = Search_Node_By_Index(_index - 1);
		delete_Node = pre_Node->Get_Next_Node();

		if (delete_Node == m_Back_Node)
		{
			m_Back_Node = pre_Node;
		}

		pre_Node->Set_Next_Node(delete_Node->Get_Next_Node());
		SAFE_DELETE(delete_Node);
	}

	void Delete_By_Value(const T& _value)
	{
		if (Empty())
		{
			return;
		}

		CNode<T>* pre_Node = m_Front_Node;
		CNode<T>* delete_Node = nullptr;

		if (_value == m_Front_Node->Get_Data())
		{
			delete_Node = m_Front_Node;
			m_Front_Node = m_Front_Node->Get_Next_Node();
			SAFE_DELETE(delete_Node);
			--m_List_Size;
			return;
		}

		while (_value != pre_Node->Get_Next_Node()->Get_Data())
		{
			if (pre_Node->Get_Next_Node() == m_Back_Node)
			{
				return;
			}
			pre_Node = pre_Node->Get_Next_Node();
		}
		delete_Node = pre_Node->Get_Next_Node();

		pre_Node->Set_Next_Node(delete_Node->Get_Next_Node());
		SAFE_DELETE(delete_Node);
		--m_List_Size;

		return;
	}

	const int& Search_Value_By_Index(const unsigned int& _index)
	{
		CNode<T>* node = Search_Node_By_Index(_index);
		
		if (node)
		{
			return node;
		}

		return nullptr;
	}

	CNode<T>* Search_Node_By_Index(const unsigned int& _index)
	{
		if (Empty())
		{
			return nullptr;
		}

		CNode<T>* node = m_Front_Node;
		int iCount = 0;

		while (_index != iCount++)
		{
			node = node->Get_Next_Node();
		}

		return node;
	}

	CNode<T>* Search_Node_By_Value(const T& _value)
	{
		if (Empty())
		{
			return nullptr;
		}

		CNode<T>* node = m_Front_Node;

		while (_value != node->Get_Data())
		{
			if (node == m_Back_Node)
			{
				return nullptr;
			}
			node = node->Get_Next_Node();
		}

		return node;
	}

	const size_t& Get_Size()
	{
		return m_List_Size;
	}

	bool Empty()
	{
		return (0 == m_List_Size);
	}

	void Release()
	{
		if (!Empty())
		{
			Delete_By_Index(0);
		}
	}

public:
	CLinkedList<T>()
		: m_Front_Node(nullptr)
		, m_Back_Node(nullptr)
		, m_List_Size(0)
	{

	}
	~CLinkedList<T>()
	{
		Release();
	}

private:
	CNode<T>* m_Front_Node;
	CNode<T>* m_Back_Node;
	size_t m_List_Size;
};
