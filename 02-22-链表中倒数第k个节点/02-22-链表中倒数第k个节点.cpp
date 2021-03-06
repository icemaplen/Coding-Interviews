// 02-22-链表中倒数第k个节点.cpp: 定义控制台应用程序的入口点。
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

ListNode* FindKthToTail(ListNode* pListHead, int k)
{
	if (pListHead == nullptr || k <= 0)
	{
		return nullptr;
	}

	ListNode* pAhead = pListHead;
	ListNode* pBehind = pListHead;

	for (int i = 0; i < k - 1; i++)
	{
		if (pAhead->m_pNext != nullptr)
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			return nullptr;
		}
	}

	while (pBehind->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}