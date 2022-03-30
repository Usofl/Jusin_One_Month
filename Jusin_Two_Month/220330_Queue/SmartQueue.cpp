#include "stdafx.h"
#include "SmartQueue.h"


CSmartQueue::CSmartQueue()
	: m_Front_Node(nullptr)
	, m_Back_Node(nullptr)
	, m_Queue_Size(0)
{
}


CSmartQueue::~CSmartQueue()
{
	Release();
}

void CSmartQueue::Enqueue(const int & _data)
{
	CNode* New_Node = new CNode(_data);
	
	if (nullptr == m_Front_Node)
	{
		m_Front_Node = New_Node;
		m_Back_Node = New_Node;
		++m_Queue_Size;
		return;
	}

	m_Back_Node->Set_Next_Node(New_Node);
	m_Back_Node = New_Node;
	++m_Queue_Size;
}

const int CSmartQueue::Dequeue()
{
	if (Empty())
	{
		return -1;
	}
	CNode* Dequeue_Node = m_Front_Node;
	const int Dequeue_Data = m_Front_Node->Get_Data();

	--m_Queue_Size;

	if (Dequeue_Node == m_Back_Node)
	{
		delete Dequeue_Node;

		m_Front_Node = nullptr;
		m_Back_Node = nullptr;

		return Dequeue_Data;
	}
	m_Front_Node = Dequeue_Node->Get_Next_Node();

	delete Dequeue_Node;

	return Dequeue_Data;
}

const size_t & CSmartQueue::Get_Size()
{
	return m_Queue_Size;
}

bool CSmartQueue::Empty()
{
	return (m_Queue_Size == 0);
}

void CSmartQueue::Release()
{
	while (!(Empty()))
	{
		Dequeue();
	}
}
