// 02-32-从上到下打印二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <queue>
#include <iostream>

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

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (pTreeRoot == nullptr)
	{
		return;
	}

	std::queue<BinaryTreeNode*> treeNodeQueue;
	treeNodeQueue.push(pTreeRoot);
	while (treeNodeQueue.empty()==false)
	{
		BinaryTreeNode* tmp = treeNodeQueue.front();
		std::cout << tmp->m_nValue << "\t";
		treeNodeQueue.pop();

		if (tmp->m_pLeft != nullptr)
		{
			treeNodeQueue.push(tmp->m_pLeft);
		}
		if (tmp->m_pRight != nullptr)
		{
			treeNodeQueue.push(tmp->m_pRight);
		}
	}
}