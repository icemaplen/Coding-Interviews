// 02-36-二叉搜索树与双向链表.cpp: 定义控制台应用程序的入口点。
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

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	ConvertNode(pRoot, &pLastNodeInList);

	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	if (pNode == nullptr)
	{
		return;
	}

	BinaryTreeNode* pCurrent = pNode;

	// 找到最左最下的节点
	if (pCurrent->m_pLeft != nullptr)
	{
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	// pLastNodeInList为双向链表的尾节点
	// 当前节点的上一个节点为链表的尾节点
	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
	{	
		// 将尾节点下个节点指向当前节点
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	// 插入新的尾节点
	// 更新尾节点
	*pLastNodeInList = pCurrent;
	// 处理右子树
	if (pCurrent->m_pRight != nullptr)
	{
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}