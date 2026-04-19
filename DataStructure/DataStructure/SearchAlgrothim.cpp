int LinearSearch(int arr[], int n, int item)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == item)
			return i;
	}
	return -1;
}
int BinarySearch(int arr[], int n, int item)
{
	int l = 0, r = n - 1, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == item)
			return m;
		else if (arr[m] > item)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}
