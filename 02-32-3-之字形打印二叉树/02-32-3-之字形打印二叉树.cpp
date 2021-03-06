// 02-32-3-之字形打印二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>

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

void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::stack<BinaryTreeNode*> level[2];
	int current = 0;
	int next = 1;

	level[current].push(pRoot);
	while (!level[0].empty()||!level[1].empty())
	{
		BinaryTreeNode* pNode = level[current].top();
		level[current].pop();

		std::cout << pNode->m_nValue << "\t";

		if (current == 0)
		{
			if (pNode->m_pLeft != nullptr)
			{
				level[next].push(pNode->m_pLeft);
			}
			if (pNode->m_pRight != nullptr)
			{
				level[next].push(pNode->m_pRight);
			}
		}
		else
		{
			if (pNode->m_pRight != nullptr)
			{
				level[next].push(pNode->m_pRight);
			}
			if (pNode->m_pLeft != nullptr)
			{
				level[next].push(pNode->m_pLeft);
			}
		}

		if (level[current].empty())
		{
			std::cout << std::endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}