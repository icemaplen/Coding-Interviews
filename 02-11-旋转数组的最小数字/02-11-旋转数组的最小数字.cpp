// 02-11-旋转数组的最小数字.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int GetMinNumber(int numbers[], int length);
int GetMinByOrder(int numbers[], int length);

int main()
{
	int nums[5] = { 3,4,5,1,2 };
	int nums2[5] = { 1,0,1,1,1 };
	std::cout << GetMinNumber(nums2, 5);

	return 0;
}

int GetMinNumber(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("输出不合法");
	}

	int index1 = 0;
	int index2 = length - 1;
	int midIndex = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			midIndex = index2;
			break;
		}

		midIndex = (index2 - index1) / 2 + index1;

		if (numbers[index1] == numbers[midIndex] && numbers[midIndex] == numbers[index2])
		{
			return GetMinByOrder(numbers, length);
		}

		if (numbers[midIndex] >= numbers[index1])
		{
			index1 = midIndex;
		}
		else if (numbers[midIndex] <= numbers[index2])
		{
			index2 = midIndex;
		}
	}

	return numbers[midIndex];
}

int GetMinByOrder(int numbers[], int length)
{
	int min = numbers[0];
	for (int i = 1; i < length; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}

	return min;
}

