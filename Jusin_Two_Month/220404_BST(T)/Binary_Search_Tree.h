#pragma once
#include "Node.h"

template<typename T>
class CBinary_Search_Tree
{
public:
	void insert_data(const T& _data)
	{
		CNode<T>* new_Node = new CNode<T>(_data);

		if (nullptr == m_Root_node)
		{
			cout << "루트 : " << _data << endl;
			m_Root_node = new_Node;
		}
		else
		{
			CNode<T>* pre_Node = m_Root_node;

			while(true)
			{
				if (_data < pre_Node->Get_Data())
				{
					if (nullptr == pre_Node->Get_Left_Node())
					{
						cout << "좌측 : " << _data << endl;
						pre_Node->Set_Left_Node(new_Node);
						new_Node->Set_Head_Node(pre_Node);
						return;
					}
					else
					{
						pre_Node = pre_Node->Get_Left_Node();
					}
				}
				else
				{
					if (nullptr == pre_Node->Get_Right_Node())
					{
						cout << "우측 : " << _data << endl;
						pre_Node->Set_Right_Node(new_Node);
						new_Node->Set_Head_Node(pre_Node);
						return;
					}
					else
					{
						pre_Node = pre_Node->Get_Right_Node();
					}
				}
			}
		}
	}

	void insert_node(CNode<T>* _head_node, CNode<T>* _delete_node, CNode<T>* _node)
	{
		if (m_Root_node == _delete_node)
		{
			m_Root_node = _node;
		}
		else
		{
			if (_delete_node == _head_node->Get_Left_Node())
			{
				_head_node->Set_Left_Node(_node);
			}
			else if (_delete_node == _head_node->Get_Right_Node())
			{
				_head_node->Set_Right_Node(_node);
			}
		}

		_node->Set_Head_Node(_head_node);
		if (_delete_node->Get_Left_Node() != _node)
		{
			_node->Set_Left_Node(_delete_node->Get_Left_Node());
		}

		if (_delete_node->Get_Right_Node() != _node)
		{
			_node->Set_Right_Node(_delete_node->Get_Right_Node());
		}
	}

	CNode<T>* search_Node_Value(const T& _value)
	{
		if (!Empty())
		{
			CNode<T>* node = m_Root_node;

			while (nullptr != node)
			{
				if (_value == node->Get_Data())
				{
					return node;
				}
				else if (_value < node->Get_Data())
				{
					node = node->Get_Left_Node();
				}
				else
				{
					node = node->Get_Right_Node();
				}
			}
		}

		return nullptr;
	}

	bool Remove_Node(const T& _data)
	{
		CNode<T>* delete_Node = search_Node_Value(_data);

		if (nullptr == delete_Node)
		{
			return false;
		}

		CNode<T>* head_Node = delete_Node->Get_Head_Node();
		CNode<T>* right_Node = delete_Node->Get_Right_Node();
		CNode<T>* left_Node = delete_Node->Get_Left_Node();

		if (nullptr != right_Node && right_Node != delete_Node)
		{
			cout << right_Node->Get_Data() << endl;
			while (true)
			{
				if (nullptr != right_Node->Get_Left_Node())
				{
					right_Node = right_Node->Get_Left_Node();
				}
				else
				{
					if (nullptr != right_Node->Get_Right_Node())
					{
						right_Node->Get_Right_Node()->Set_Head_Node(right_Node->Get_Head_Node());
					}

					if (right_Node == right_Node->Get_Head_Node()->Get_Right_Node())
					{
						right_Node->Get_Head_Node()->Set_Right_Node(right_Node->Get_Right_Node());
					}
					else if (right_Node == right_Node->Get_Head_Node()->Get_Left_Node())
					{
						right_Node->Get_Head_Node()->Set_Left_Node(right_Node->Get_Right_Node());
					}

					break;
				}
			}

			insert_node(head_Node, delete_Node, right_Node);
			SAFE_DELETE(delete_Node);
			return true;
		}

		if (nullptr != left_Node && left_Node != delete_Node)
		{
			while (true)
			{
				if (nullptr != left_Node->Get_Right_Node())
				{
					left_Node = left_Node->Get_Right_Node();
				}
				else
				{
					if (nullptr != left_Node->Get_Left_Node())
					{
						left_Node->Get_Left_Node()->Set_Head_Node(left_Node->Get_Head_Node());
					}

					if (left_Node == left_Node->Get_Head_Node()->Get_Right_Node())
					{
						left_Node->Get_Head_Node()->Set_Right_Node(left_Node->Get_Left_Node());
					}
					else if (left_Node == left_Node->Get_Head_Node()->Get_Left_Node())
					{
						left_Node->Get_Head_Node()->Set_Left_Node(left_Node->Get_Left_Node());
					}


					break;
				}
			}

			insert_node(head_Node, delete_Node, left_Node);
			SAFE_DELETE(delete_Node);
			return true;
		}
		else
		{
			if (delete_Node == m_Root_node)
			{
				m_Root_node = nullptr;
			}
			else
			{
				if (delete_Node == head_Node->Get_Left_Node())
				{
					head_Node->Set_Left_Node(nullptr);
				}
				else if (delete_Node == head_Node->Get_Right_Node())
				{
					head_Node->Set_Right_Node(nullptr);
				}
			}
			SAFE_DELETE(delete_Node);
			return true;
		}

		return false;
	}

	bool Empty()
	{
		return (nullptr == m_Root_node);
	}

	void Release()
	{
		while (!Empty())
		{
			Remove_Node(m_Root_node->Get_Data());
		}
	}

public:
	CBinary_Search_Tree()
		: m_Root_node(nullptr)
	{

	}

	~CBinary_Search_Tree() { Release(); }

private:
	CNode<T>* m_Root_node;
};