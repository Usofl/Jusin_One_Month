#pragma once

class CNode
{
public:
	CNode();
	CNode(const int& _data);
	~CNode();

	void Set_Data(const int& _data);
	void Set_Next_Node(CNode* _next_node);

	const int& Get_Data();
	CNode* Get_Next_Node();

private:
	int m_Data;
	CNode* m_Next_Node;
};