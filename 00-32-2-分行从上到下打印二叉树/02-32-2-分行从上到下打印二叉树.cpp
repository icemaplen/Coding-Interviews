// 02-32-2-分行从上到下打印二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>

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

	std::queue<BinaryTreeNode*> treeNodeQueue;
	treeNodeQueue.push(pRoot);
	int toBePrinted = 1;
	int nextLayerNode = 0;

	while (treeNodeQueue.empty() == false)
	{
		BinaryTreeNode* node = treeNodeQueue.front();

		if (node->m_pLeft != nullptr)
		{
			nextLayerNode++;
			treeNodeQueue.push(node->m_pLeft);
		}
		if (node->m_pRight != nullptr)
		{
			nextLayerNode++;
			treeNodeQueue.push(node->m_pRight);
		}

		std::cout << node->m_nValue << "\t";
		treeNodeQueue.pop();
		toBePrinted--;

		if (toBePrinted == 0)
		{
			std::cout << std::endl;
			toBePrinted = nextLayerNode;
			nextLayerNode = 0;
		}
	}
}