int GetSumFrom0ToN(int n)
{
	if (n == 1)
		return 1;
	return n + GetSumFrom0ToN(n - 1);
}
//5 * 5 * 5

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
