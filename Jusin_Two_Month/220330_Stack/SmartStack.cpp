#include "stdafx.h"
#include "SmartStack.h"


CSmartStack::CSmartStack()
	: m_Top_Node(nullptr)
	, m_Stack_Size(0)
{
}


CSmartStack::~CSmartStack()
{
	Release();
}

void CSmartStack::Push(const int & _data)
{
	CNode* New_Node = new CNode(_data);

	New_Node->Set_Pre_Node(m_Top_Node);

	++m_Stack_Size;
	m_Top_Node = New_Node;
}

const int CSmartStack::Pop()
{
	if (Empty())
	{
		return -1;
	}

	CNode* Pop_Node = m_Top_Node;
	int Pop_Data = Pop_Node->Get_Data();

	m_Top_Node = Pop_Node->Get_Pre_Node();

	delete Pop_Node;

	--m_Stack_Size;

	return Pop_Data;
}

const int & CSmartStack::Top()
{
	return m_Top_Node->Get_Data();
}

bool CSmartStack::Empty()
{
	return (0 == m_Stack_Size);
}

const size_t& CSmartStack::Get_Size()
{
	return m_Stack_Size;
}

void CSmartStack::Release()
{
	while (!Empty())
	{
		Pop();
	}
}
