#pragma once
#include "Node.h"

template<typename T>
class CDoubleLinkedList
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
			cout << i++ << ". " << node->Get_Data() << endl;
			node = node->Get_Next_Node();
		}

		cout << i << ". " << node->Get_Data() << endl;
	}

	void Reverse_Render()
	{
		if (Empty())
		{
			return;
		}

		CNode<T>* node = m_Back_Node;
		unsigned int i = static_cast<unsigned int>(m_List_Size) - 1;

		while (m_Front_Node != node)
		{
			cout << i-- << ". " << node->Get_Data() << endl;
			node = node->Get_Pre_Node();
		}

		cout << i << ". " << node->Get_Data() << endl;
	}

	void Push(const T& _data)
	{
		CNode<T>* new_node = new CNode<T>(_data);
		if (Empty())
		{
			m_Front_Node = new_node;
			m_Back_Node = new_node;
		}

		m_Back_Node->Set_Next_Node(new_node);
		new_node->Set_Pre_Node(m_Back_Node);
		new_node->Set_Next_Node(new_node);
		m_Back_Node = new_node;
		++m_List_Size;
	}

	void Insert_By_Index(const unsigned int& _index, const T& _data)
	{
		CNode<T>* new_Node = nullptr;

		if (_index > m_List_Size)
		{
			return;
		}
		else if (m_List_Size == _index)
		{
			Push(_data);
			return;
		}
		else if (0 == _index)
		{
			new_Node = new CNode<T>(_data);
			new_Node->Set_Next_Node(m_Front_Node);
			
			m_Front_Node->Set_Pre_Node(new_Node);
			m_Front_Node = new_Node;
			
			++m_List_Size;
			
			return;
		}

		new_Node = new CNode<T>(_data);
		CNode<T>* next_Node = Search_Node_By_Index(_index);

		new_Node->Set_Next_Node(next_Node);
		new_Node->Set_Pre_Node(next_Node->Get_Pre_Node());

		next_Node->Get_Pre_Node()->Set_Next_Node(new_Node);
		next_Node->Set_Pre_Node(new_Node);

		++m_List_Size;
	}

	void Insert_By_Value(const int& _value, const int& _data)
	{
		CNode<T>* pre_Node = Search_Node_By_Value(_value);

		if (pre_Node == nullptr)
		{
			return;
		}
		else if (pre_Node == m_Front_Node)
		{
			Insert_By_Index(0, _data);
			return;
		}
		else if (pre_Node == m_Back_Node)
		{
			Push(_data);
			return;
		}

		CNode<T>* New_Node = new CNode<T>(_data);

		New_Node->Set_Pre_Node(pre_Node);
		New_Node->Set_Next_Node(pre_Node->Get_Next_Node());

		pre_Node->Get_Next_Node()->Set_Pre_Node(New_Node);
		pre_Node->Set_Next_Node(New_Node);

		++m_List_Size;
	}

	void Delete_By_Index(const unsigned int& _index)
	{
		if (_index >= m_List_Size)
		{
			return;
		}

		CNode<T>* delete_Node = nullptr;

		if (0 == _index)
		{
			delete_Node = m_Front_Node;
			m_Front_Node = m_Front_Node->Get_Next_Node();
			SAFE_DELETE(delete_Node);
			--m_List_Size;
			return;
		}
		if(_index == m_List_Size - 1)
		{
			delete_Node = m_Back_Node;
			m_Back_Node = m_Back_Node->Get_Pre_Node();
			SAFE_DELETE(delete_Node);
			--m_List_Size;
			return;
		}

		delete_Node = Search_Node_By_Index(_index);
		delete_Node->Get_Pre_Node()->Set_Next_Node(delete_Node->Get_Next_Node());
		delete_Node->Get_Next_Node()->Set_Pre_Node(delete_Node->Get_Pre_Node());
		--m_List_Size;
	}

	void Delete_By_Value(const T& _value)
	{
		CNode<T>* delete_Node = Search_Node_By_Value(_value);

		if (delete_Node == nullptr)
		{
			return;
		}
		else if (delete_Node == m_Front_Node)
		{
			Delete_By_Index(0);
			return;
		}
		else if (delete_Node == m_Back_Node)
		{
			unsigned int i = static_cast<unsigned int>(m_List_Size) - 1;
			Delete_By_Index(i);
			return;
		}

		delete_Node->Get_Pre_Node()->Set_Next_Node(delete_Node->Get_Next_Node());
		delete_Node->Get_Next_Node()->Set_Pre_Node(delete_Node->Get_Pre_Node());
		--m_List_Size;
	}

	const int& Search_Value_By_Index(const unsigned int& _index)
	{
		CNode<T>* node = Search_Node_By_Index(_index);

		if (nullptr == node)
		{
			return 0;
		}

		return node->Get_Data();
	}

	CNode<T>* Search_Node_By_Index(const unsigned int& _index)
	{
		if (_index > m_List_Size)
		{
			return nullptr;
		}

		if (_index == m_List_Size - 1)
		{
			return m_Back_Node;
		}
		CNode<T>* node = m_Front_Node;
		int i = 0;

		while (_index != i++)
		{
			node = node->Get_Next_Node();
		}

		return node;
	}

	CNode<T>* Search_Node_By_Value(const T& _value)
	{
		CNode<T>* node = m_Front_Node;

		if (!Empty())
		{
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

		return nullptr;
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
	CDoubleLinkedList<T>() 
		: m_Front_Node(nullptr)
		, m_Back_Node(nullptr)
		, m_List_Size(0) 
	{
	}

	~CDoubleLinkedList<T>()
	{
		Release();
	}

private:
	CNode<T>* m_Front_Node;
	CNode<T>* m_Back_Node;

	size_t m_List_Size;
};
