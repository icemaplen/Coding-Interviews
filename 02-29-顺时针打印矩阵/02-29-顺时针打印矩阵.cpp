// 02-29-顺时针打印矩阵.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int main()
{
	return 0;
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == nullptr || columns <= 0 || rows <= 0)
	{
		return;
	}

	int start = 0;
	while (columns > start * 2 || rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i < endX; i++)
	{
		PrintNumber(numbers[start][i]);
	}
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; i++)
		{
			PrintNumber(numbers[i][endX]);
		}
	}

	if (start < endX&&start < endY)
	{
		for (int i=endX-1;i>=start;i--)
		{
			PrintNumber(numbers[endY][i]);
		}
	}

	if (start < endX&&start < endY - 1)
	{
		for (int i=endY-1;i>=start+1;i--)
		{
			PrintNumber(numbers[i][start]);
		}
	}
}

void PrintNumber(int number)
{
	std::cout << number << "\t";
}