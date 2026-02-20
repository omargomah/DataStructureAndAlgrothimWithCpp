#include <iostream>
using namespace std;

template <class T>
class DoubleLinkedList
{
	struct Node
	{
		T item;
		Node* next;
		Node* prev;
	};
	int length;
	Node* head;
	Node* tail;
	void FirstNode(Node* newNode)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		head = tail = newNode;
	}
	void DeleteLastNode()
	{
		delete head;
		head = tail = NULL;
		length = 0;
	}
public:
	DoubleLinkedList()
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
			newNode->prev = NULL;
			head->prev = newNode;
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
			newNode->prev = tail;
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
			newNode->prev = temp;
			temp->next->prev = newNode;
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
		head->prev = NULL;
		temp->next = NULL;
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

		Node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		temp->prev = NULL;
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
			cur->next->prev = prev;
			delete cur;
			length--;
		}
	}
	void DisplayLikeQueue()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void DisplayLikeStack()
	{
		Node* temp = tail;
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->prev;
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
			cur->prev = next;
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
