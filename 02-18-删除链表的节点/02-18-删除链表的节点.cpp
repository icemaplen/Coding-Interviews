// 02-18-删除链表的节点.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode
{
	int m_value;
	ListNode* m_pNext;
};


int main()
{
	return 0;
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (*pListHead == nullptr || pToBeDeleted == nullptr)
	{
		return;
	}

	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_value = pNode->m_value;
		pToBeDeleted->m_pNext = pNode->m_pNext;
		delete pNode;
	}
	else if (*pListHead == pToBeDeleted)
	{
		*pListHead = (*pListHead)->m_pNext;
		delete *pListHead;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pToBeDeleted->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* preNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != nullptr&&pNode->m_value == pNext->m_value)
		{
			needDelete = true;
		}

		if (!needDelete)
		{
			preNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_value;
			ListNode* pToBeDeleted = pNode;
			while (pToBeDeleted != nullptr&&pToBeDeleted->m_value == value)
			{
				pNext = pToBeDeleted->m_pNext;
				delete pToBeDeleted;
				pToBeDeleted = pNext;

				if (preNode == nullptr)
				{
					*pHead = pNext;
				}
				else
				{
					preNode->m_pNext = pNext;
				}
				pNode = pNext;
			}
		}
	}
}