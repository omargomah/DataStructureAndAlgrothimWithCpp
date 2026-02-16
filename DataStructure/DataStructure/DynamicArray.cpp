#include <iostream>
using namespace std;

class DynamicArray
{
	int* arr;
	int length;
	int MaxSize;
public:
	DynamicArray(int size = 10)
	{
		MaxSize = size < 0 ? 100 : size;
		arr = new int[MaxSize];
		length = 0;
	}

	bool IsFull()
	{
		return length == MaxSize;
	}

	void InsertAt(int pos, int element)
	{
		if (IsFull())
		{
			cout << "the Array is full" << endl;
			return;
		}
		if (pos < 0 || pos > length)
		{
			cout << "the index out of range" << endl;
			return;
		}
		for (int i = length; i > pos; i--)
			arr[i] = arr[i - 1];
		arr[pos] = element;
		length++;
	}

	bool IsOutOfRange(int index)
	{
		return index < 0 || index > length - 1;
	}

	bool IsEmpty()
	{
		return length == 0;
	}

	void DeleteAt(int pos)
	{
		if (IsEmpty())
		{
			cout << "The array is Empty" << endl;
			return;
		}

		if (IsOutOfRange(pos))
		{
			cout << "the index out of range" << endl;
			return;
		}
		for (int i = pos; i < (length - 1); i++)
			arr[i] = arr[i + 1];
		length--;
	}

	void Push(int element)
	{
		InsertAt(length, element);
	}

	void Enqueue(int element)
	{
		InsertAt(0, element);
	}

	int GetElement(int index)
	{
		if (IsOutOfRange(index))
			return NULL;
		return arr[index];
	}

	void UpdateElement(int index, int newValue)
	{
		if (IsOutOfRange(index))
		{
			cout << "Index out of Range" << endl;
			return;
		}
		arr[index] = newValue;
	}

	void Display()
	{
		cout << "[ ";
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]\n";
	}

	int Search(int element)
	{
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == element)
				return i;
		}
		return -1;
	}

	void PushIfNotExist(int element)
	{
		if (Search(element) != -1)
			return;
		Push(element);
	}

	int Size()
	{
		return length;
	}

	void Clear()
	{
		length = 0;
	}

	~DynamicArray()
	{
		delete[] arr;
	}

};
