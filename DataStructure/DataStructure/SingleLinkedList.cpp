#include <iostream>
using namespace std;

template <class T>
class singleLinkedList
{
	struct Node
	{
		T item;
		Node* next;
	};
	int length;
	Node* head;
	Node* tail;
	void FirstNode(Node* newNode)
	{
		newNode->next = NULL;
		head = tail = newNode;
	}
	void DeleteLastNode()
	{
		delete head;
		head = tail = NULL;
		length = 0;
	}
public:
	singleLinkedList()
	{
		length = 0;
		head = tail = NULL;
	}
	bool IsEmpty()
	{
		return length == 0;
	}
	void Enqueue(T element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		if (IsEmpty())
			FirstNode(newNode);
		else
		{
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	void Push(T element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		if (IsEmpty())
			FirstNode(newNode);
		else
		{
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
	void Insert(T element, int pos)
	{
		if (pos < 0 || pos > length)
			cout << "Invalid position!" << endl;
		else if (pos == 0)
			Enqueue(element);
		else if (pos == length)
			Push(element);
		else
		{
			Node* temp = head;
			for (int i = 1; i < pos; i++)
				temp = temp->next;
			Node* newNode = new Node;
			newNode->item = element;
			newNode->next = temp->next;
			temp->next = newNode;
			length++;
		}
	}
	void Dequeue()
	{
		if (length == 1)
		{
			DeleteLastNode();
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		length--;
	}
	void Pop()
	{
		if (length == 1)
		{
			DeleteLastNode();
			return;
		}

		Node* temp = head;
		for (int i = 2; i < length; i++)
		{
			temp = temp->next;
		}
		tail = temp;
		temp = temp->next;
		tail->next = NULL;
		delete temp;
		length--;
	}
	void RemoveAt(int pos)
	{
		if (pos < 0 || pos > length)
			cout << "Invalid position!" << endl;
		else if (pos == 0)
			Dequeue();
		else if (pos == length)
			Pop();
		else
		{
			Node* cur = head, * prev = head;
			for (int i = 1; i < pos; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			cur->next = NULL;
			delete cur;
			length--;
		}
	}
	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void Clear()
	{
		while (!IsEmpty())
			Dequeue();
	}
	void Reverse()
	{
		if (IsEmpty() || length == 1)
			return;
		Node* prev = NULL, * cur = head, * next = head->next;
		tail = head;
		while (next != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}
	int Search(T element)
	{
		if (IsEmpty())
			return -1;
		Node* temp = head;
		for (int i = 0; i < length; i++)
		{
			if (temp->item == element)
				return i;
			temp = temp->next;
		}
		return -1;
	}

};

class LinkedListV2
{
	struct Node
	{
		int data;
		Node* Next;
	};
	Node* Head;
public:
	LinkedListV2()
	{
		Head = NULL;
	}
	bool IsEmpty()
	{
		return Head == NULL;
	}
	int Count()
	{
		int i = 0;
		Node* temp = Head;
		while (temp != NULL)
		{
			i++;
			temp = temp->Next;
		}
		return i;
	}
	void InsertAtFirst(int item)
	{
		Node* newNode = new Node;
		newNode->data = item;
		newNode->Next = Head;;
		Head = newNode;
	}
	void InsertAtLast(int item)
	{
		if (IsEmpty())
		{
			InsertAtFirst(item);
			return;
		}
		Node* temp = Head, * newNode = new Node;
		newNode->data = item;
		newNode->Next = NULL;
		while (temp->Next != NULL)
			temp = temp->Next;
		temp->Next = newNode;
	}
	void InsertAtAnyPosition(int pos, int item)
	{
		int size = Count();
		if (pos < 0 || pos > size)
			cout << "the index out of range" << endl;
		else if (pos == 0)
			InsertAtFirst(item);
		else if (pos == size)
			InsertAtLast(item);
		else
		{
			Node* temp = Head, * newNode = new Node;
			newNode->data = item;
			for (int i = 0; i < pos - 1; i++)
				temp = temp->Next;
			newNode->Next = temp->Next;
			temp->Next = newNode;
		}
	}
	void Display()
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->Next;
		}
		cout << endl;
	}
	bool Search(int item)
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			if (temp->data == item)
				return true;
			temp = temp->Next;
		}
		return false;
	}
	void DeleteAtFirst()
	{
		if (IsEmpty())
		{
			cout << "the LinkedList is empty" << endl;
			return;
		}
		Node* deleted = Head;
		Head = Head->Next;
		delete deleted;
	}
	void DeleteAtLast()
	{
		if (IsEmpty())
		{
			cout << "the LinkedList is empty" << endl;
			return;
		}
		Node* deleted = Head, * prev = NULL;
		while (deleted->Next != NULL)
		{
			prev = deleted;
			deleted = deleted->Next;
		}
		if (prev == NULL)
			DeleteAtFirst();
		else
		{
			prev->Next = NULL;
			delete deleted;
		}
	}
	void DeleteAtAnyPosition(int pos)
	{
		int size = Count();
		if (pos < 0 || pos >(size - 1))
			cout << "the index out of range" << endl;
		else if (pos == 0)
			DeleteAtFirst();
		else if (pos == size - 1)
			DeleteAtLast();
		else
		{
			Node* prev = Head, * deleted = NULL;
			for (int i = 0; i < pos - 1; i++)
				prev = prev->Next;
			deleted = prev->Next;
			prev->Next = deleted->Next;
			delete deleted;
		}
	}
	void Reverse()
	{
		if (IsEmpty())
			return;
		Node* prev = NULL, * cur = Head, * next = Head;
		while (cur != NULL)
		{
			next = cur->Next;
			cur->Next = prev;
			prev = cur;
			cur = next;
		}
		Head = prev;
	}
};
