#pragma once
#include "Node.h"

class CSmartQueue
{
public:
	CSmartQueue();
	~CSmartQueue();

	void Enqueue(const int& _data);
	const int Dequeue();

	const size_t& Get_Size();

	bool Empty();

	void Release();

private:
	CNode* m_Front_Node;
	CNode* m_Back_Node;

	size_t m_Queue_Size;
};

