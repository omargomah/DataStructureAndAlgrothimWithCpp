#include <iostream>
using namespace std;
template <class t>
class QueueArray
{
	t* array;
	int length;
	int front;
	int back;
	int MaxSize;

public:

	QueueArray(int QSize)
	{
		if (QSize <= 0)
			QSize = 100;
		MaxSize = QSize;
		array = new t[QSize];
		front = 0;
		back = QSize - 1;
		length = 0;
	}
	void Enqueue(t element)
	{
		if (IsFull())
		{
			cout << "Queue is Full increase size\n";
			return;
		}
		back = (back + 1) % MaxSize;
		array[back] = element;
		length++;
	}
	bool IsFull()
	{
		return length == MaxSize;
	}
	void Dequeue()
	{
		if (IsEmpty())
		{
			cout << "the Queue is Empty\n";
			return;
		}
		front = (front + 1) % MaxSize;
		length--;
	}
	bool IsEmpty()
	{
		return length == 0;
	}
	t Front()
	{
		if (IsEmpty())
			return -1;
		return array[front];
	}
	t Back()
	{
		if (IsEmpty())
			return -1;
		return array[back];
	}
	void Display()
	{
		cout << "[ ";
		int temp = front;
		for (int tempLength = length; tempLength > 0;tempLength--)
		{
			cout << array[front] << " ";
			front = (front + 1) % MaxSize;
		}
		cout << "]\n";

	}


};
