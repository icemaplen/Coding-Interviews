// 02-17-打印从1到最大的n位数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include "iostream"

void Point1ToMaxOfDigits(int n);
bool Increment(char* number);
void PrintNumber(char* number);

void Point1ToMaxOfDigits2(int n);
void Point1ToMaxOfDigits2Core(char* number, int length, int index);

int main()
{
	Point1ToMaxOfDigits2(2);

	return 0;
}

void Point1ToMaxOfDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[] number;
}

bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakekOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakekOver;
		if (i == nLength - 1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakekOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			//nTakekOver = 0;
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

void PrintNumber(char* number)
{
	bool isBeginning = true;
	int length = strlen(number);
	for (int i = 0; i < length; i++)
	{
		if (isBeginning&&number[i] != '0')
		{
			isBeginning = false;
		}

		if (!isBeginning)
		{
			printf("%c", number[i]);
		}
	}

	std::cout << "\t";
}


// 递归解法
void Point1ToMaxOfDigits2(int n)
{
	char* numbers = new char[n + 1];
	numbers[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		numbers[0] = i + '0';
		Point1ToMaxOfDigits2Core(numbers, n, 0);
	}
}

void Point1ToMaxOfDigits2Core(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Point1ToMaxOfDigits2Core(number, length, index + 1);
	}
}