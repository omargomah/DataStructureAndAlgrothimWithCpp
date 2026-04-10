#include <iostream>
using namespace std;
int GetSumFrom0ToN(int n)
{
	if (n == 1)
		return 1;
	return n + GetSumFrom0ToN(n - 1);
}

int GetPower(int x, int y)
{
	if (y == 1)
		return x;
	return x * GetPower(x, y - 1);
}
int Product(int x, int y, bool first = true)
{
	if (first)
	{
		if (x < y)
		{
			y += x;
			x = y - x;
			y = y - x;
		}
	}
	if (y == 1)
		return x;
	return x + Product(x, y - 1, false);
}
int GetSumOfDigit(int n)
{
	if (n == 0)
		return 0;
	return n % 10 + GetSumOfDigit(n / 10);
}

void ShowDigitOfNum(int n)
{
	int num = n % 10;
	if (n == 0)
		return;
	ShowDigitOfNum(n / 10);
	cout << num << endl;
}
void GetReversedNum(int n)
{
	int i = n % 10;
	if (n == 0)
		return;
	cout << i;
	GetReversedNum(n / 10);
}
void Fibonacci(int n, int prev = 0, int cur = 0)
{
	if (n == 0)
		return;
	cout << cur << " ";
	Fibonacci(n - 1, cur, (cur + prev) == 0 ? 1 : cur + prev);
}

int GetFibonacciAtPos(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return GetFibonacciAtPos(n - 1) + GetFibonacciAtPos(n - 2);
}
int GetSum(int n)
{
	if (n == 1)
		return 1;
	return n + GetSum(n - 1);
}