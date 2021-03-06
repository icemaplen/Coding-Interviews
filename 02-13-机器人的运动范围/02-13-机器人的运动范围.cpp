// 02-13-机器人的运动范围.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	return 0;
}

int MovingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows < 0 || cols < 0)
	{
		return 0;
	}

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int count = MovingCountCore(threshold, rows, cols, 0, 0, visited);
}

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (Check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + row] = true;

		count = 1 + MovingCountCore(threshold, rows, cols, row + 1, col, visited) +
			MovingCountCore(threshold, rows, cols, row - 1, col, visited) +
			MovingCountCore(threshold, rows, cols, row, col + 1, visited) +
			MovingCountCore(threshold, rows, cols, row, col + 1, visited);
	}

	return count;
}

bool Check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row > 0 && row < rows && col>0 && col < cols && visited[row*cols + col] == false && GetDigitSum(row, col) <= threshold)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GetDigitSum(int row, int col)
{
	int result = 0;
	while (row > 0)
	{
		result += row % 10;
		row /= 10;
	}
	while (col > 0)
	{
		result += col % 10;
		col /= 10;
	}

	return result;
}