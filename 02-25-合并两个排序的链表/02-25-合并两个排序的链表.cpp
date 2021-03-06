// 02-25-合并两个排序的链表.cpp: 定义控制台应用程序的入口点。
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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	else if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode* newHead = nullptr;
	if (pHead1->m_nValue <= pHead2->m_nValue)
	{
		newHead = pHead1;
		pHead1 = pHead1->m_pNext;
	}
	else
	{
		newHead = pHead2;
		pHead2 = pHead2->m_pNext;
	}
	ListNode* pNode = newHead;

	while (pHead1 != nullptr && pHead2 != nullptr)
	{
		if (pHead1->m_nValue <= pHead2->m_nValue)
		{
			pNode->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		else
		{
			newHead->m_pNext = pHead2;
			pHead2 = pHead2->m_pNext;
		}
		pNode = pNode->m_pNext;
	}

	while (pHead1 != nullptr)
	{
		pNode->m_pNext = pHead1;
		pHead1 = pHead1->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pHead2 != nullptr)
	{
		pNode->m_pNext = pHead2;
		pHead2 = pHead2->m_pNext;
		pNode = pNode->m_pNext;
	}

	return newHead;
}

// 递归解法
ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	else if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode* newHead = nullptr;
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		newHead = pHead1;
		newHead->m_pNext = Merge2(pHead1->m_pNext, pHead2);
	}
	else
	{
		newHead = pHead2;
		newHead->m_pNext = Merge2(pHead1, pHead2->m_pNext);
	}

	return newHead;
}