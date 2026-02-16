#include <iostream>
using namespace std;
template <class t>
class QueueLinkedList
{
	struct Node
	{
		t item;
		Node* Next;

	};

	int length;
	Node* front;
	Node* back;

public:

	QueueLinkedList()
	{
		front = back = NULL;
		length = 0;
	}
	void Enqueue(t element)
	{
		Node* newPtr = new Node;
		if (newPtr == NULL)
		{
			cout << "the memory is full";
			return;
		}
		newPtr->item = element;
		newPtr->Next = NULL;
		if (IsEmpty())
			front = back = newPtr;
		else
		{
			back->Next = newPtr;
			back = newPtr;
		}
		length++;
	}
	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}

	void Dequeue()
	{
		if (IsEmpty())
		{
			cout << "the Queue is Empty\n";
			return;
		}
		Node* temp = front;
		front = front->Next;
		length--;
		if (length == 0)
			back = NULL;
		delete temp;
	}
	bool IsEmpty()
	{
		return length == 0;
	}
	t Front()
	{
		if (IsEmpty())
			return -1;
		return front->item;
	}
	t Back()
	{
		if (IsEmpty())
			return -1;
		back->item;
	}
	void Display()
	{
		cout << "[ ";
		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->Next;
		}
		cout << "]\n";

	}
	int Size()
	{
		return length;
	}

};
