#pragma once

class CNode
{
public:
	CNode();
	CNode(const int& _data);
	~CNode();

	void Set_Data(const int& _data);
	void Set_Next_Node(CNode* _next_node);
	void Set_Pre_Node(CNode* _pre_Node);

	const int& Get_Data();
	CNode* Get_Next_Node();
	CNode* Get_Pre_Node();

private:
	int m_Data;
	CNode* m_Next_Node;
	CNode* m_Pre_Node;
};
