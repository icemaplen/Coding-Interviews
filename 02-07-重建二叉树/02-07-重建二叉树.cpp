// 02-07-重建二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_PRight;
};

int main()
{
	return 0;
}

BinaryTreeNode* Constuct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

//             Root
//               |
// 前序遍历序列： 1 2 4 7 3 5 6 8
// 中序遍历序列： 4 7 2 1 5 3 8 6
//                    |
//            左子树 Root 右子树

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInoder, int* endInoder)
{
	// 前序遍历序列第一个数字是根节点的值
	int rootValue = startPreorder[0];
	// 创建父节点
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_PRight = nullptr;

	// 递归结束条件
	// 仅剩一个节点
	if (startPreorder == endPreorder)
	{
		// 最后前序序列和中序序列都会剩下一个数，即第一个，且相等。递归结束
		if (startInoder == endInoder && *startPreorder == *startInoder)
		{
			return root;
		}
		else
		{
			throw std::exception("序列有误");
		}
	}

	// 在中序遍历序列中找到根节点的值
	int* rootInoder = startInoder;
	while (rootInoder <= endInoder && *rootInoder != rootValue)
	{
		rootInoder++;
	}

	if (rootInoder == endInoder && *rootInoder != rootValue)
	{
		throw std::exception("序列有误");

	}

	int leftLength = rootInoder - startInoder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInoder, rootInoder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_PRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInoder + 1, endInoder);
	}

	return root;
}

