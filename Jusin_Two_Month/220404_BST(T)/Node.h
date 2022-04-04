#pragma once

template<typename T>
class CNode
{
public:
	const T& Get_Data()
	{
		return m_Data;
	}

	CNode<T>* Get_Head_Node()
	{
		return m_Head_Node;
	}

	CNode<T>* Get_Right_Node()
	{
		return m_Right_Node;
	}

	CNode<T>* Get_Left_Node()
	{
		return m_Left_Node;
	}

	void Set_Head_Node(CNode<T>* _head_Node)
	{
		m_Head_Node = _head_Node;
	}

	void Set_Right_Node(CNode<T>* _right_Node)
	{
		m_Right_Node = _right_Node;
	}

	void Set_Left_Node(CNode<T>* _left_Node)
	{
		m_Left_Node = _left_Node;
	}

public:
	CNode(const T& _data)
		: m_Data(_data)
		, m_Head_Node(nullptr)
		, m_Left_Node(nullptr)
		, m_Right_Node(nullptr)
	{

	}

	~CNode() {};

private:
	T m_Data;
	CNode<T>* m_Head_Node;
	CNode<T>* m_Right_Node;
	CNode<T>* m_Left_Node;
};