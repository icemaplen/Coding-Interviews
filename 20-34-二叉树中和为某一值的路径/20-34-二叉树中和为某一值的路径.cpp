// 20-34-二叉树中和为某一值的路径.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <vector>

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

// 栈结构，只能得到栈顶元素
void FindPath(BinaryTreeNode* pRoot, int sum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::stack<BinaryTreeNode*> nodes;
	int currentSum = 0;
	FindPathCore(pRoot, nodes, sum, currentSum);
}

void FindPathCore(BinaryTreeNode* pRoot, std::stack<BinaryTreeNode*> nodes, int sum, int currentSum)
{
	currentSum += pRoot->m_nValue;
	nodes.push(pRoot);

	bool isLeaf = pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr;
	if (currentSum == sum && isLeaf)
	{
		std::cout << "找到了";
	}

	if (pRoot->m_pLeft != nullptr)
	{
		FindPathCore(pRoot->m_pLeft, nodes, sum, currentSum);
	}
	if (pRoot->m_pRight != nullptr)
	{
		FindPathCore(pRoot->m_pRight, nodes, sum, currentSum);
	}

	nodes.pop();
}

// vector
void FindPath2(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::vector<int> path;
	int currentSum = 0;

}

void FindPathCore2(BinaryTreeNode* pRoot, std::vector<int> path, int expectedSum, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr;
	if (currentSum == expectedSum && isLeaf)
	{
		std::cout << "发现了路径：";
		std::vector<int>::iterator iter = path.begin();
		for (;iter!=path.end();iter++)
		{
			std::cout << *iter << "\t";
		}
	}

	if (pRoot->m_pLeft != nullptr)
	{
		FindPathCore2(pRoot->m_pLeft, path, expectedSum, currentSum);
	}
	if (pRoot->m_pRight != nullptr)
	{
		FindPathCore2(pRoot->m_pRight, path, expectedSum, currentSum);
	}

	path.pop_back();
}
