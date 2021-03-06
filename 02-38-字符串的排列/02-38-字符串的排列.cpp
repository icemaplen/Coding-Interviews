// 02-38-字符串的排列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

void Permutation(char* pStr);
void Permutation(char* pStr, char* pBegin);

int main()
{
	char strs[] = "abcd";
	Permutation(strs);
    return 0;
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			char tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;

			Permutation(pStr, pBegin + 1);

			tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;
		}
	}
}