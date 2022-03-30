#pragma once
#include "Node.h"

class CSmartStack
{
public:
	CSmartStack();
	~CSmartStack();

	void Push(const int& _data);
	const int Pop();
	const int& Top();

	bool Empty();

	const size_t& Get_Size();

	void Release();

private:
	CNode* m_Top_Node;
	size_t m_Stack_Size;
};

