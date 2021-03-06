// 02-33-二叉搜索树的后序遍历序列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

bool VerifySquenceOfBST(int sequence[], int length);

int main()
{
	int numbers[] = { 1,2 };

	if (VerifySquenceOfBST(numbers, 7))
	{
		std::cout << "是二叉搜索树的后序遍历序列\n";
	}
	else
	{
		std::cout << "不是二叉搜索树的后序遍历序列\n";
	}

    return 0;
}

bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
	{
		return false;
	}

	int root = sequence[length - 1];
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}

	int j = i;
	for (; j < length - 1; j++)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	bool left = true;
	if (i > 0)
	{
		left = VerifySquenceOfBST(sequence, i);
	}

	bool right = true;
	if (i < length - 1)
	{
		right = VerifySquenceOfBST(sequence + i, length - 1 - i);
	}

	return left && right;
}