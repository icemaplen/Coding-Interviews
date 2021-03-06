// 02-03-数组中重复的数字.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int FindRepeatNumber(int array[], int n);

int main()
{
	int array[] = { 2,3,1,0,2,5,3 };
	std::cout<< FindRepeatNumber(array, 7);

    return 0;
}

int FindRepeatNumber(int array[], int n)
{
	if (array == nullptr || n < 2)
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		while (array[i] != i)
		{
			if (array[i] == array[array[i]])
			{
				return array[i];
			}

			int temp = array[i];
			array[i] = array[array[i]];
			array[temp] = temp;
		}
	}

	return -1;
}

int FindRepeatNumber2(int array[], int n)
{
	if (array == nullptr || n < 2)
	{
		return -1;
	}

	int start = 1;
	int end = array[n - 1];

	while (start <= end)
	{
		int middle = (end - start) / 2 + start;
		int count = CountRange(array, n, start, middle);

		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}

		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}

	return -1;
}

int CountRange(const int numbers[], int length, int start, int end)
{
	if (numbers == nullptr)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] <= end && numbers[i] >= start)
		{
			count++;
		}
	}
	return count;
}
