// 02-05-替换空格.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void ReplaceWithSpace(char str[], int length);

int main()
{
	char strs[50] = "We are happy.";
	ReplaceWithSpace(strs,50);
	cout << strs << endl;

	return 0;
}

void ReplaceWithSpace(char str[], int length)
{
	if (str == nullptr || length <= 0)
	{
		return;
	}

	int originLength = 0;
	int blankNumber = 0;

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			blankNumber++;
		}
		originLength++;
		i++;
	}

	int newLength = originLength + 2 * blankNumber;
	if (newLength > length)
	{
		return;
	}

	int newIndex = newLength + 1;
	int originIndex = originLength + 1;

	while (originIndex > 0 && newIndex > 0)
	{
		if (str[originIndex] == ' ')
		{
			str[newIndex--] = '0';
			str[newIndex--] = '2';
			str[newIndex--] = '%';
			originIndex--;
		}
		else
		{
			str[newIndex--] = str[originIndex--];
		}
	}
}

