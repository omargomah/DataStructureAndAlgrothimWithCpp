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
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Merge(int arr[], int l, int r, int m)
{
	int n1 = m - l + 1, n2 = r - m, x = l, y = m + 1, k;
	int* left = new int[n1], * right = new int[n2];
	for (int i = 0; i < n1; i++)
		left[i] = arr[x++];
	for (int i = 0; i < n2; i++)
		right[i] = arr[y++];
	x = 0; y = 0; k = l;
	while (x < n1 && y < n2)
	{
		if (left[x] < right[y])
			arr[k++] = left[x++];
		else
			arr[k++] = right[y++];
	}
	while (x < n1)
		arr[k++] = left[x++];
	while (y < n2)
		arr[k++] = right[y++];
}

//1 --> 5    6   3
void Div(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		Div(arr, l, m);
		Div(arr, m + 1, r);
		Merge(arr, l, r, m);
	}
}








int Sort(int arr[], int l, int r)
{
	int pivot = l, temp;
	while (true)
	{
		while (pivot != r && arr[pivot] <= arr[r])
			r--;
		if (pivot == r)
			break;
		temp = arr[pivot];
		arr[pivot] = arr[r];
		arr[r] = temp;
		pivot = r;
		while (pivot != l && arr[pivot] >= arr[l])
			l++;
		if (pivot == l)
			break;
		temp = arr[pivot];
		arr[pivot] = arr[l];
		arr[l] = temp;
		pivot = l;
	}
	return pivot;
}
void Partition(int arr[], int l, int r)
{
	if (l < r)
	{
		int pivot = Sort(arr, l, r);
		Partition(arr, l, pivot - 1);
		Partition(arr, pivot + 1, r);
	}
}

