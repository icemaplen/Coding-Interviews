// 02-04-二维数组中的查找.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

bool Find(int matrix[], int rows, int columns, int number);

int main()
{
	int array[4][4] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};

	if (Find(&array[0][0], 4, 4, 7))
	{
		std::cout << "找到了" << std::endl;
	}
	else
	{
		std::cout << "没有找到" << std::endl;
	}

	return 0;
}

bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row <= rows && column > 0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > number)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}

	return found;
}
