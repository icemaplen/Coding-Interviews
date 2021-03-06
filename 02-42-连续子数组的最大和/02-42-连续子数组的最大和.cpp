// 02-42-连续子数组的最大和.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int FindGreatestSumOfSubArray(int* pData, int length);

int main()
{
	int nums[] = { 1,-2,3,10,-4,7,2,-5 };
	std::cout << FindGreatestSumOfSubArray(nums, 8);

    return 0;
}

int FindGreatestSumOfSubArray(int* pData, int length)
{
	if (pData == nullptr || length < 1)
	{
		throw new std::exception("输入有误");
		return 0;
	}

	int sum = 0;
	int greatestSum = 0x80000000;
	for (int i = 0; i < length; i++)
	{
		if (sum <= 0)
		{
			sum = pData[i];
		}
		else
		{
			sum += pData[i];
		}

		if (sum > greatestSum)
		{
			greatestSum = sum;
		}
	}

	return greatestSum;
}