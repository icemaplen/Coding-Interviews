// 02-06-从头到尾打印链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stack"
#include "iostream"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

int main()
{
    return 0;
}


void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		std::cout << pNode->m_nValue << "\t";
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}

		std::cout << pHead->m_nValue << "\t";
	}
}
