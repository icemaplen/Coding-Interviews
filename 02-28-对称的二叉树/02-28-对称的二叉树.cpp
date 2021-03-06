// 02-28-对称的二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int main()
{
    return 0;
}

bool IsSymmetrical(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return false;
	}

	return IsSymmetrical(pRoot, pRoot);
}

bool IsSymmetrical(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
	if (pNode1 == nullptr&&pNode2 == nullptr)
	{
		return true;
	}

	if (pNode1 == nullptr || pNode2 == nullptr)
	{
		return false;
	}

	if (pNode1->m_nValue != pNode2->m_nValue)
	{
		return false;
	}

	return IsSymmetrical(pNode1->m_pLeft, pNode2->m_pRight) && IsSymmetrical(pNode1->m_pRight, pNode2->m_pLeft);
}