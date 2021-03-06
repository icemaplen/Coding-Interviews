// 02-12-矩阵中的路径.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
    return 0;
}

bool HasPath(char* martrix, int rows, int cols, char* str)
{
	if (martrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
	{
		return false;
	}

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (HasPathCore(martrix, rows, cols, row, col, str, pathLength, visited))
			{
				return true;
			}
		}
	}
}

bool HasPathCore(const char* martrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
	{
		return true;
	}

	bool hasPath = false;
	if (row > 0 && row < rows&&col>0 && col < cols&&martrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
	{
		pathLength++;
		visited[row*cols + col] = true;

		hasPath = HasPathCore(martrix, rows, cols, row - 1, col, str, pathLength, visited) ||
			HasPathCore(martrix, rows, cols, row + 1, col, str, pathLength, visited) ||
			HasPathCore(martrix, rows, cols, row, col - 1, str, pathLength, visited) ||
			HasPathCore(martrix, rows, cols, row, col + 1, str, pathLength, visited);
		if (hasPath == false)
		{
			pathLength--;
			visited[row*cols + col] = false;
		}
	}

	return hasPath;
}

