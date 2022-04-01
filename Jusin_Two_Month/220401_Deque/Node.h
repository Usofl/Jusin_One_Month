#pragma once

template<typename T>
class CNode
{
public:

	const T& Get_Data()
	{
		return m_Data;
	}

	CNode<T>* Get_Next_Node()
	{
		return m_Next_Node;
	}

	CNode<T>* Get_Pre_Node()
	{
		return m_Pre_Node;
	}

	void Set_Next_Node(CNode<T>* _next_Node)
	{
		m_Next_Node = _next_Node;
	}

	void Set_Pre_Node(CNode<T>* _pre_Node)
	{
		m_Pre_Node = _pre_Node;
	}

public:
	CNode<T>(const T& _data)
		: m_Data(_data)
		, m_Next_Node(nullptr)
		, m_Pre_Node(nullptr)
	{

	}
	~CNode<T>() = default;

private:
	T m_Data;
	CNode<T>* m_Next_Node;
	CNode<T>* m_Pre_Node;
};
