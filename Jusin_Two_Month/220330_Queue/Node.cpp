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

const int & CNode::Get_Data()
{
	return m_Data;
}

CNode * CNode::Get_Next_Node()
{
	return m_Next_Node;
}