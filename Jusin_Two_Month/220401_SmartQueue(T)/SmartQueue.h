#pragma once
#include "Node.h"

template<typename T>
class CSmartQueue
{
public:

	void Enqueue(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);

		if (Empty())
		{
			m_Front_Node = new_Node;
			m_Back_Node = new_Node;
		}

		m_Back_Node->Set_Next_Node(new_Node);
		m_Back_Node = new_Node;
		++m_Queue_Size;
	}

	const T Dequeue()
	{
		if (Empty())
		{
			return 0;
		}
		CNode<T>* dequeue_Node = m_Front_Node;
		T data = dequeue_Node->Get_Data();

		m_Front_Node = m_Front_Node->Get_Next_Node();
		SAFE_DELETE(dequeue_Node);
		--m_Queue_Size;

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
		return m_Queue_Size;
	}

	bool Empty()
	{
		return (0 == m_Queue_Size);
	}

	void Release()
	{
		if (!Empty())
		{
			Dequeue();
		}
	}

public:
	CSmartQueue<T>()
		: m_Front_Node(nullptr)
		, m_Back_Node(nullptr)
		, m_Queue_Size(0)
	{

	}
	~CSmartQueue<T>()
	{
		Release();
	}

private:
	CNode<T>* m_Front_Node;
	CNode<T>* m_Back_Node;
	size_t m_Queue_Size;
};
