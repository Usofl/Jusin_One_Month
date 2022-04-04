// 220404_BST(T).cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Binary_Search_Tree.h"

int main()
{
	CBinary_Search_Tree<int> my_bst;

	my_bst.insert_data(15);
	my_bst.insert_data(9);
	my_bst.insert_data(7);
	my_bst.insert_data(2);
	my_bst.insert_data(19);
	my_bst.insert_data(64);
	my_bst.insert_data(34);
	my_bst.insert_data(22);

	my_bst.Remove_Node(22);
    return 0;
}

