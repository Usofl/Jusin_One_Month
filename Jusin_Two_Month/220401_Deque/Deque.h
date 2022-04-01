#pragma once
#include "Node.h"

template<typename T>
class CDeque
{
public:

	void Push_Front(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);

		if (Empty())
		{
			m_Front_Node = new_Node;
			m_Back_Node = new_Node;
		}

		new_Node->Set_Next_Node(m_Front_Node);
		m_Front_Node->Set_Pre_Node(new_Node);
		m_Front_Node = new_Node;
		++m_Deque_Size;
	}
	
	void Push_Back(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);

		if (Empty())
		{
			m_Front_Node = new_Node;
			m_Back_Node = new_Node;
		}

		new_Node->Set_Pre_Node(m_Back_Node);
		m_Back_Node->Set_Next_Node(new_Node);
		m_Back_Node = new_Node;
		++m_Deque_Size;
	}

	const T Pop_Front()
	{
		if (Empty())
		{
			return 0;
		}
		CNode<T>* pop_Node = m_Front_Node;
		T data = m_Front_Node->Get_Data();

		m_Front_Node = m_Front_Node->Get_Next_Node();
		SAFE_DELETE(pop_Node);
		--m_Deque_Size;

		return data;
	}

	const T Pop_Back()
	{
		if (Empty())
		{
			return 0;
		}
		CNode<T>* pop_Node = m_Back_Node;
		T data = m_Back_Node->Get_Data();

		m_Back_Node = m_Back_Node->Get_Pre_Node();
		SAFE_DELETE(pop_Node);
		--m_Deque_Size;

		return data;
	}

	const T Front()
	{
		T data = m_Front_Node->Get_Data();

		return data;
	}

	const T Back()
	{
		T data = m_Back_Node->Get_Data();

		return data;
	}

	const size_t& Get_Size()
	{
		return m_Deque_Size;
	}

	bool Empty()
	{
		return (0 == m_Deque_Size);
	}

	void Release()
	{
		if (!Empty())
		{
			Pop_Front();
		}
	}

public:
	CDeque<T>()
		: m_Front_Node(nullptr)
		, m_Back_Node(nullptr)
		, m_Deque_Size(0)
	{
	}

	~CDeque<T>()
	{
		Release();
	}

private:
	CNode<T>* m_Front_Node;
	CNode<T>* m_Back_Node;

	size_t m_Deque_Size;
};

