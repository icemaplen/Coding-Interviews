// 02-14-剪绳子.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

int GetMax(int length);

int main()
{
	std::cout << GetMax(8);

	return 0;
}

// 动态规划
int GetMax(int length)
{
	if (length < 2)
	{
		return 0;
	}
	else if (length == 2)
	{
		return 1;
	}
	else if (length == 3)
	{
		return 2;
	}

	int* max = new int[length + 1];
	max[0] = 0;
	max[1] = 1;
	max[2] = 2;
	max[3] = 3;

	int maxNumber = 0;
	for (int i = 4; i <= length; i++)
	{
		maxNumber = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			if (maxNumber < max[j] * max[i - j])
			{
				maxNumber = max[j] * max[i - j];
			}
		}

		max[i] = maxNumber;
	}

	maxNumber = max[length];
	delete[] max;

	return maxNumber;
}

// 贪心算法
int GetMax2(int length)
{
	if (length < 2)
	{
		return 0;
	}
	else if (length == 2)
	{
		return 1;
	}
	else if (length == 3)
	{
		return 2;
	}

	int timesOf3 = length / 3;
	if (length - timesOf3 * 3 == 1)
	{
		timesOf3 -= 1;
	}

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}