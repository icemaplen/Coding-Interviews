// 02-08-二叉树的下一个节点.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

int main()
{
	return 0;
}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* node = pNode->m_pRight;
		while (node->m_pLeft != nullptr)
		{
			node = node->m_pLeft;
		}
		pNext = node;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* parent = pNode->m_pParent;
		while (parent->m_pParent!=nullptr&&parent!=parent->m_pParent->m_pLeft)
		{
			parent = parent->m_pParent;
		}

		pNext = parent;
	}

	return pNext;
}

