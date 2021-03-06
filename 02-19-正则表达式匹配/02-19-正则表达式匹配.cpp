// 02-19-正则表达式匹配.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

bool Match(char* str, char* pattern);
bool MatchCore(char* str, char* pattern);

int main()
{
	char str[] = "aaa";
	char pattern[] = ".*";

	std::cout << Match(str, pattern);

    return 0;
}

bool Match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
	{
		return false;
	}

	return MatchCore(str, pattern);
}

bool MatchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern) == '.'&&*str != '\0')
		{
				// 字符只出现一次
			return MatchCore(str + 1, pattern + 2) 
				// 字符重复多次
				|| MatchCore(str + 1, pattern) 
				// 字符只有0次
				|| MatchCore(str, pattern + 2);
		}
		else
		{
			return MatchCore(str, pattern + 2);
		}
	}

	if (*pattern == *str || (*pattern) == '.'&&*str != '\0')
	{
		return MatchCore(str + 1, pattern + 1);
	}

	return false;
}