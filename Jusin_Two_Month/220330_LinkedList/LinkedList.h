#pragma once
#include "Node.h"

class CLinkedList
{
public:
	CLinkedList();
	~CLinkedList();

	void Render();

	void Push(const int& _data);
	void Insert_By_Index(const unsigned int& _index, const int& _data);
	void Insert_By_Value(const int& _value, const int& _data);

	void Delete_By_Index(const unsigned int& _index);
	void Delete_By_Value(const int& _value);

	const int& Search_Value_By_Index(const unsigned int& _index);
	CNode* Search_Node_By_Index(const unsigned int& _index);
	CNode* Search_Node_By_Value(const int& _value);

	const size_t& Get_size();
	bool Empty();

	void Release();

private:
	CNode* m_Front_Node;
	CNode* m_Back_Node;

	size_t m_List_Size;
};