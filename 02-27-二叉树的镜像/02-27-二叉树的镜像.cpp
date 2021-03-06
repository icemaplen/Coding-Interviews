// 02-27-二叉树的镜像.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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

void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	
	if (pNode->m_pLeft != nullptr || pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* temp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = temp;
	}

	MirrorRecursively(pNode->m_pLeft);
	MirrorRecursively(pNode->m_pRight);
}