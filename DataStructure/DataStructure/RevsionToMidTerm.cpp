#include <iostream>
#include <stack>
#include <string>
using namespace std;

//class stack
//{
//private:
//	int* arr;
//	int Max_size;
//	int top;
//public:
//	stack(int size)
//	{
//		if (size > 0)
//			Max_size = size;
//		top = -1;
//		arr = new int[Max_size];
//	}
//	bool Is_Empty()
//	{
//		return top == -1;
//	}
//	bool Is_full()
//	{
//		return top == Max_size - 1;
//	}
//	void Push(int item)
//	{
//		if (Is_full())
//		{
//			cout << "the stack is full" << endl;
//			return;
//		}
//		arr[++top] = item;
//	}
//	void Pop()
//	{
//		if (Is_Empty())
//		{
//			cout << "the stack is empty" << endl;
//			return;
//		}
//		--top;
//	}
//	void Display()
//	{
//		if (Is_Empty())
//		{
//			cout << "the stack is empty" << endl;
//			return;
//		}
//		cout << "[ ";
//		int temp = top;
//		do
//		{
//			cout << arr[temp--] << " ";
//		} while (temp >= 0);
//		cout << "]"<<endl;
//	}
//	int GetTop()
//	{
//		if (Is_Empty())
//		{
//			cout << "the stack is empty" << endl;
//			return NULL;
//		}
//		return arr[top];
//	}
//};
//class Queue
//{
//	int front, rear;
//	int* arr;
//	int Max_size = 100;
//public:
//	Queue(int size)
//	{
//		if (size > 0)
//			Max_size = size;
//		arr = new int[Max_size];
//		front = rear = -1;
//	}
//	bool IsEmpty()
//	{
//		return front == -1;
//	}
//	bool IsFull()
//	{
//		return  (rear + 1) % Max_size == front;
//	}
//	void Enqueue(int item)
//	{
//		if (IsFull())
//		{
//			cout << "the Queue is Full" << endl;
//			return;
//		}
//		else if (IsEmpty())
//			front = 0;
//		rear = (rear + 1) % Max_size;
//		arr[rear] = item;
//	}
//	void Dequeue()
//	{
//		if (IsEmpty())
//		{
//			cout << "the Queue is Empty" << endl;
//			return;
//		}
//		if (front == rear)
//			front = rear = -1;
//		else
//			front = (front + 1) % Max_size;
//	}
//	int GetFront()
//	{
//		if (IsEmpty())
//		{
//			cout << "the Queue is Empty" << endl;
//			return NULL;
//		}
//		return arr[front];
//	}
//	void Display()
//	{
//		int temp = front;
//		if (IsEmpty())
//		{
//			cout << "the Queue is Empty" << endl;
//			return;
//		}
//		cout << "[ ";
//		while (temp != rear)
//		{
//			cout << arr[temp] <<" ";
//			temp = (temp + 1) % Max_size;
//		}
//		cout << arr[temp]<<" ]"<<endl;
//
//	}
//};
//


class LinkedList
{
	struct Node
	{
		int item;
		Node* Next;
	};
	Node* Head;
public:
	LinkedList()
	{
		Head = NULL;
	}
	int Count()
	{
		int i = 0;
		Node* temp = Head;
		while (temp != NULL)
		{
			temp = temp->Next;
			i++;
		}
		return i;
	}
	bool IsEmpty()
	{
		return Head == NULL;
	}
	void InsertFirst(int item)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->Next = Head;
		Head = newNode;
	}
	void InsertLast(int item)
	{
		if (IsEmpty())
		{
			InsertFirst(item);
			return;
		}
		Node* newNode = new Node, * temp = Head;
		newNode->item = item;
		newNode->Next = NULL;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = newNode;
	}
	void InsertAtPosition(int pos, int item)
	{
		int length = Count();
		if (pos < 0 || pos > length)
			cout << "index out of range" << endl;
		else if (pos == 0)
			InsertFirst(item);
		else if (pos == length)
			InsertLast(item);
		else
		{
			Node* temp = Head;
			for (int i = 0; i <= pos - 2; i++)
				temp = temp->Next;
			Node* newNode = new Node;
			newNode->item = item;
			newNode->Next = temp->Next;
			temp->Next = newNode;
		}
	}
	void Display()
	{
		Node* temp = Head;
		cout << "[ ";
		while (temp != NULL)
		{
			cout << temp->item << " ";
			temp = temp->Next;
		}
		cout << "]" << endl;
	}
	int SearchForElement(int item)
	{
		Node* temp = Head;
		int i = 0;
		while (temp != NULL)
		{
			if (item == temp->item)
				return i;
			temp = temp->Next;
			i++;
		}
		return -1;
	}
	void InsertBeforeItem(int itemToAddBefore, int newItem)
	{
		Node* cur = Head, * prev = NULL;
		while (cur != NULL && cur->item != itemToAddBefore)
		{
			prev = cur;
			cur = cur->Next;
		}
		if (cur == NULL)
			cout << "element to insert before not found" << endl;
		else if (prev == NULL)
			InsertFirst(newItem);
		else
		{
			Node* newNode = new Node;
			newNode->item = newItem;
			newNode->Next = cur;
			prev->Next = newNode;
		}
	}
	void DeleteFirst()
	{
		if (IsEmpty())
			cout << "the list is empty" << endl;
		else
		{
			Node* temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}
	void DeleteLast()
	{
		if (IsEmpty())
			cout << "the list is empty" << endl;
		else
		{
			Node* cur = Head, * prev = NULL;
			while (cur->Next != NULL)
			{
				prev = cur;
				cur = cur->Next;
			}
			if (prev == NULL)
				DeleteFirst();
			else
			{
				prev->Next = NULL;
				delete cur;
			}
		}
	}
	void DeleteAtAnyPos(int pos)
	{
		int length = Count();
		if (pos < 0 || pos > length - 1)
			cout << "index out of range" << endl;
		else if (pos == 0)
			DeleteFirst();
		else if (pos == length - 1)
			DeleteLast();
		else
		{
			Node* temp = Head;
			for (int i = 0; i <= pos - 2; i++)
				temp = temp->Next;
			Node* NodeWillDelete = temp->Next;
			temp->Next = NodeWillDelete->Next;
			delete NodeWillDelete;
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

void ConvertDecimalToBinary()
{
	int num;
	cin >> num;
	stack<int> binary;
	if (num < 0)
	{
		num = abs(num);
		cout << 1;
	}
	else
		cout << 0;
	do
	{
		binary.push(num % 2);
		num /= 2;
	} while (num != 0);

	while (!binary.empty())
	{
		cout << binary.top();
		binary.pop();
	}
}
int GetPriority2(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '^')
		return 3;
	return 0;
}
string ConvertFromInfixToPostfix2(string exp)
{
	stack<char> c;
	char x;
	string result;
	for (int i = 0; i < exp.length(); i++)
	{
		x = exp[i];
		if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
		{
			if (c.empty() || x == '(')
				c.push(x);
			else if (x == ')')
			{
				while (c.top() != '(')
				{
					result += c.top();
					c.pop();
				}
				c.pop();
			}
			else
			{
				while (!c.empty() && GetPriority2(c.top()) >= GetPriority2(x))
				{
					result += c.top();
					c.pop();
				}
				c.push(x);
			}
		}
		else
			result += x;

	}
	while (!c.empty())
	{
		result += c.top();
		c.pop();
	}
	return result;


}
string ConvertFromInfixToPrefix2(string exp)
{
	stack<char> c;
	char x;
	string result;
	for (int i = exp.length() - 1; i > -1; i--)
	{
		x = exp[i];
		if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
		{
			if (c.empty() || x == ')')
				c.push(x);
			else if (x == '(')
			{
				while (c.top() != ')')
				{
					result = c.top() + result;
					c.pop();
				}
				c.pop();
			}
			else
			{
				while (!c.empty() && GetPriority2(c.top()) > GetPriority2(x))
				{
					result = c.top() + result;
					c.pop();
				}
				c.push(x);
			}
		}
		else
			result = x + result;

	}
	while (!c.empty())
	{
		result = c.top() + result;
		c.pop();
	}
	return result;


}
char open[] = { '(','[','{' };
char close[] = { ')',']','}' };
bool IsOpenBracket(char x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x == open[i])
			return true;
	}
	return false;
}
bool IsClosedBrackets(char x)
{
	for (int i = 0; i < 3; i++)
	{
		if (x == close[i])
			return true;
	}
	return false;
}
bool IsClosedForLastOpen(char op, char cl)
{
	if (op == open[0] && cl == close[0])
		return true;
	else if (op == open[1] && cl == close[1])
		return true;
	else if (op == open[2] && cl == close[2])
		return true;
	return false;
}
bool IsBalanced(string exp)
{
	stack<char> c;
	for (int i = 0; i < exp.length();i++)
	{
		if (IsOpenBracket(exp[i]))
			c.push(exp[i]);
		else if (IsClosedBrackets(exp[i]))
		{
			if (!IsClosedForLastOpen(c.top(), exp[i]))
				return false;
			c.pop();
		}
	}
	if (c.empty())
		return true;
	return false;
}
double EvaluationPostfix(string exp)
{
	stack<double> c;
	char x;
	double result;
	for (int i = 0; i < exp.length(); i++)
	{
		x = exp[i];
		if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
		{
			double num2 = c.top(); c.pop();
			double num1 = c.top(); c.pop();
			switch (exp[i])
			{
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num1 - num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
			{
				if (num2 == 0)
				{
					cout << "you can't divide by zero" << endl;
					return NULL;
				}
				result = num1 / num2;
				break;
			}
			case '^':
				result = pow(num1, num2);
				break;
			default:
				break;
			}
			c.push(result);
		}
		else
			c.push(x - 48);
	}
	return c.top();
}