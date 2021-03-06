// 02-20-表示数值的字符串.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

bool IsNumberic(const char* str);
bool ScanUnsignedInteger(const char** str);

int main()
{
	char str[] = "-45.51e-10";
	std::cout << IsNumberic(str);

    return 0;
}

bool IsNumberic(const char* str)
{
	if (str == nullptr)
	{
		return false;
	}

	bool isNumberic = ScanUnsignedInteger(&str);

	if (*str == '.')
	{
		str++;
		isNumberic = ScanUnsignedInteger(&str) || isNumberic;
	}

	if (*str == 'e' || *str == 'E')
	{
		str++;
		isNumberic = isNumberic && ScanUnsignedInteger(&str);
	}

	return isNumberic && *str == '\0';
}

bool ScanInteger(const char** str)
{
	return false;
}

bool ScanUnsignedInteger(const char** str)
{
	if (**str == '+' || **str == '-')
	{
		(*str)++;
	}

	const char* front = *str;
	while (**str!='\0'&& **str>='0'&&**str<='9')
	{
		(*str)++;
	}

	return *str > front;
}