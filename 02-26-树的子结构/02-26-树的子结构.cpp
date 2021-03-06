// 02-26-树的子结构.cpp: 定义控制台应用程序的入口点。
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

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr&&pRoot2 != nullptr)
	{
		if (pRoot1->m_nValue == pRoot2->m_nValue)
		{
			result = DoesTree1HavaTree2(pRoot1, pRoot2);
		}

		if (!result)
		{
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);
		}

		if (!result)
		{
			result = HasSubtree(pRoot2->m_pRight, pRoot2);
		}
	}

	return result;
}

bool DoesTree1HavaTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
	{
		return true;
	}
	if (pRoot1 == nullptr)
	{
		return false;
	}

	if (pRoot1->m_nValue != pRoot2->m_nValue)
	{
		return false;
	}
	else
	{
		return DoesTree1HavaTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HavaTree2(pRoot1->m_pRight, pRoot2->m_pRight);
	}
}