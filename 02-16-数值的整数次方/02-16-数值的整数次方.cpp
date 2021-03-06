// 02-16-数值的整数次方.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

double Power(double base, int exponent);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

int main()
{
	std::cout << Power(0, -5);

    return 0;
}

double Power(double base, int exponent)
{
	double result = 0;
	if (exponent == 0)
	{
		result = 1;
	}
	else if (exponent < 0)
	{
		if (base == 0)
		{
			result = 0;
		}
		else
		{
			exponent = -exponent;
			result = 1 / PowerWithUnsignedExponent(base, exponent);
		}
	}
	else
	{
		if (base == 0)
		{
			result = 0;
		}
		else
		{
			result = PowerWithUnsignedExponent(base, exponent);
		}
	}
	
	return result;
}

// ***********************
// dalao写的算法就是牛批 _(:з」∠)_
// 像我这种鶸就会写个for循环
// ***********************
//
// 求a的n次方
// n为偶数 a^n = a^(n/2) *  a^(n/2)
// n为奇数 a^n = a^((n - 1)/2) *  a^((n - 1)/2) * a
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	else if (exponent == 1)
	{
		return base;
	}

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;

	// 判断exponent是否为奇数
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}

	return result;
}