// 00-01-链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <stack>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);
void PrintListReversingly_Iteratice(ListNode* pHead);

int main()
{
	/*ListNode* pList = nullptr;
	AddToTail(&pList, 1);
	AddToTail(&pList, 2);
	AddToTail(&pList, 3);
	RemoveNode(&pList, 2);
	PrintListReversingly_Iteratice(pList);*/

	int* p = nullptr;
	delete p;

	return 0;
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
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

	ListNode* pToBeDeleted = nullptr;

	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr&&pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintListReversingly_Iteratice(ListNode* pHead)
{
	std::stack<ListNode*> nodeStack;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodeStack.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodeStack.empty())
	{
		pNode = nodeStack.top();
		std::cout << pNode->m_nValue << "\t";
		nodeStack.pop();
	}
}

