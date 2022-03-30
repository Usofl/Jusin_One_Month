#include "stdafx.h"
#include "Node.h"

CNode::CNode()
	: m_Data(0)
	, m_Next_Node(nullptr)
{
}

CNode::CNode(const int& _data)
	: m_Data(_data)
	, m_Next_Node(nullptr)
	, m_Pre_Node(nullptr)
{
}

CNode::~CNode()
{
}

void CNode::Set_Data(const int & _data)
{
	m_Data = _data;
}

void CNode::Set_Next_Node(CNode * _next_node)
{
	m_Next_Node = _next_node;
}

void CNode::Set_Pre_Node(CNode* _pre_Node)
{
	m_Pre_Node = _pre_Node;
}

const int & CNode::Get_Data()
{
	return m_Data;
}

CNode * CNode::Get_Next_Node()
{
	return m_Next_Node;
}

CNode * CNode::Get_Pre_Node()
{
	return m_Pre_Node;
}