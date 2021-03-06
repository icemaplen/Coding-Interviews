// 02-39-数组中出现次数超过一半的数字.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int MoreThanHalfNum(int* numbers, int length);
bool CheckMoreThanHalf(int* numbers, int length, int number);

int main()
{
	int ns[] = { 1,2,3,2,2,2,5,4,2 };
	std::cout << MoreThanHalfNum(ns, 9);

    return 0;
}

int MoreThanHalfNum(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
	{
		return -1;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}

	if (CheckMoreThanHalf(numbers, length, result))
	{
		return result;
	}
	else
	{
		return -1;
	}
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}

	return times * 2 > length;
}