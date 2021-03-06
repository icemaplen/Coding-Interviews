// 02-31-栈的压入、弹出序列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

int main()
{
	return 0;
}

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;
	if (pPush != nullptr&&pPop != nullptr&&nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		while (pNextPop - pPop < nLength)
		{
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush == nLength)
				{
					break;
				}

				stackData.push(*pNextPush);
				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
			{
				break;
			}

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
		{
			return true;
		}
	}

	return bPossible;
}