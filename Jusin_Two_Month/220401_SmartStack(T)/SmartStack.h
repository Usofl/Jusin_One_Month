#pragma once
#include "Node.h"

template<typename T>
class CSmartStack
{
public:

	void Push(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);

		if (!Empty())
		{
			new_Node->Set_Pre_Node(m_Top_Node);
		}

		m_Top_Node = new_Node;
		++m_Stack_Size;
	}

	const T Pop()
	{
		if (Empty())
		{
			return 0;
		}
		CNode<T>* pop_Node = m_Top_Node;
		T data = m_Top_Node->Get_Data();

		m_Top_Node = m_Top_Node->Get_Pre_Node();
		SAFE_DELETE(pop_Node);
		--m_Stack_Size;

		return data;
	}

	const T Top()
	{
		T data = m_Top_Node->Get_Data();

		return data;
	}

	const size_t& Get_Size()
	{
		return m_Stack_Size;
	}

	bool Empty()
	{
		return (0 == m_Stack_Size);
	}

	void Release()
	{
		if (!Empty())
		{
			Pop();
		}
	}

public:
	CSmartStack<T>()
		: m_Top_Node(nullptr)
		, m_Stack_Size(0)
	{

	}
	~CSmartStack<T>()
	{
		Release();
	}

private:
	CNode<T>* m_Top_Node;
	size_t m_Stack_Size;
};
