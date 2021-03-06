// 02-10-斐波那契数列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

long long Fibonacci2(unsigned int n);

int main()
{
	std::cout << Fibonacci2(10);

    return 0;
}

// 递归实现
// 效率低
long long Fibonacci(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 1);
}

// 从下到上计算
long long Fibonacci2(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	long long number1 = 0;
	long long number2 = 1;
	long long result = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		result = number1 + number2;
		number1 = number2;
		number2 = result;
	}

	return result;
}
