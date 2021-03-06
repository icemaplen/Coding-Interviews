// 02-23-链表中环的入口节点.cpp: 定义控制台应用程序的入口点。
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

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode* pSlow = pHead;
	ListNode* pFast = pHead;

	while (pFast->m_pNext != nullptr)
	{
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast->m_pNext != nullptr)
		{
			pFast = pFast->m_pNext;
		}
		else
		{
			return nullptr;
		}

		if (pSlow == pFast)
		{
			return pSlow;
		}
	}

	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
	{
		return nullptr;
	}

	int nodeNumberInLoop = 1;
	ListNode* pNode = meetingNode->m_pNext;
	while (pNode != meetingNode)
	{
		nodeNumberInLoop++;
		pNode = pNode->m_pNext;
	}

	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;
	for (int i = 0; i < nodeNumberInLoop; i++)
	{
		pFast = pFast->m_pNext;
	}

	while (pFast != pSlow)
	{
		pFast = pFast->m_pNext;
		pSlow = pSlow->m_pNext;
	}
	return pFast;
}