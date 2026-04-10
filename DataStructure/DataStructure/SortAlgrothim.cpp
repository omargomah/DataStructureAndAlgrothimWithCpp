#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{
	int min, temp;
	for (int i = 0; i < (n - 1); i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
void BubbleSort(int arr[], int n)
{
	int temp; bool flag;
	for (int i = 0; i < (n - 1); i++)
	{
		flag = true;
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = false;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag)
			break;
	}
}
void InsertionSort(int arr[], int n)
{
	int r, temp;
	for (int i = 1; i < n; i++)
	{
		r = i;
		while (r > 0 && arr[r] < arr[r - 1])
		{
			temp = arr[r];
			arr[r] = arr[r - 1];
			arr[r - 1] = temp;
			r--;
		}
	}
}
