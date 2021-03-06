// 02-37-序列化二叉树.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

void Serialize(BinaryTreeNode* pRoot, std::ostream& stream)
{
	if (pRoot == nullptr)
	{
		stream << "$";
	}
	stream << pRoot->m_nValue << ',';
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

void Deserialize(BinaryTreeNode** pRoot, std::istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

bool ReadStream(std::istream& stream, int* number)
{
	char c;
	stream >> c;
	if (c == '$')
	{
		return false;
	}
	else
	{
		*number = c - '0';
		return true;
	}
}