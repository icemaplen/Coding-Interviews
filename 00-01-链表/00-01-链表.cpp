// 00-01-链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


int main()
{
	return 0;
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode;
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode* pToBeRemove = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeRemove = *pHead;
		(*pHead)->m_pNext = (*pHead)->m_pNext->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeRemove = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeRemove != nullptr)
	{
		delete pToBeRemove;
		pToBeRemove = nullptr;
	}
}

