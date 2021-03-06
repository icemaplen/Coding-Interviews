// 02-15-二进制中1的个数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int GetNumberOf1(int number);
int GetNumberOf1_(int number);

int main()
{
	std::cout << GetNumberOf1_(1);
    return 0;
}

int GetNumberOf1(int number)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (number&flag)
		{
			count++;
		}

		flag = flag << 1;
	}

	return count;
}

int GetNumberOf1_(int number)
{
	int count = 0;

	while (number)
	{
		count++;
		number = number&(number-1);
	}

	return count;
}