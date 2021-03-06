// 02-21-调整数组顺序使奇数位于偶数前面.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	return 0;
}

void ReorderOddEvent(int* pData, int length)
{
	if (pData == nullptr || length <= 0)
	{
		return;
	}

	int* pStart = pData;
	int* pEnd = pData + length - 1;

	while (pStart < pEnd)
	{
		while (pStart < pEnd && (*pStart & 0x1) != 0)
		{
			pStart++;
		}
		while (pStart < pEnd && (*pStart & 0x1) == 0)
		{
			pEnd--;
		}

		if (pStart < pEnd)
		{
			int temp = *pStart;
			*pStart = *pEnd;
			*pEnd = temp;
		}
	}
}
