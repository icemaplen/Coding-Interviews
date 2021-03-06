// 02-24-反转链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

int main()
{
	return 0;
}

ListNode* ReverserList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}
	else if (pHead->m_pNext == nullptr)
	{
		return pHead;
	}

	ListNode* pNode = pHead;
	pHead = nullptr;
	while (pNode != nullptr)
	{
		ListNode* currentNode = pNode;
		pNode = pNode->m_pNext;
		currentNode->m_pNext = pHead;
		pHead = currentNode;
	}

	return pHead;
}