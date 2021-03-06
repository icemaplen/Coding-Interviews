// 02-35-复杂链表的复制.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

int main()
{
    return 0;
}

// 1.复制原始链表的任意节点N并创建新节点N'，再把N'链接到N的后面；
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		ComplexListNode* pNew = new ComplexListNode();
		pNew->m_nValue = pNode->m_nValue;
		pNew->m_pNext = pNode->m_pNext;
		pNew->m_pSibling = nullptr;

		pNode->m_pNext = pNew;
		pNode = pNew->m_pNext;
	}
}

// 2.如果原始链表上的节点N的m_pSibing指向S，则它对应的复制节点N'的m_sPibing指向S的复制节点S'。
void ConnectSibingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!=nullptr)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

// 3.把第二步得到的链表拆分成两个链表，奇数位置上的节点组成原始链表，偶数位置上的节点组成复制出来的链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = nullptr;
	ComplexListNode* pClonedNode = nullptr;
	
	// 为了获取头结点，并初始化，所以不放入while循环中
	if (pNode != nullptr)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode!=nullptr)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;

		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}