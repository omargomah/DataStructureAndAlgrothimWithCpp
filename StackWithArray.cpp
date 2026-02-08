#include <iostream>
using namespace std;

template <class t>
class Stack
{
private:
    t array[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void Push(t element)
    {
        if (IsFull())
            cout << "The Stack is full" << endl;
        else
            array[++top] = element;
    }
    t Pop()
    {
        if (IsEmpty())
        {
            cout << "The Stack is empty" << endl;
            return -1;
        }
        else
            return array[top--];
    }
    void GetTop(t &element)
    {
        element = array[top];
    }
    bool IsFull()
    {
        return top == 99;
    }
    bool IsEmpty()
    {
        return top == -1;
    }
    void Print()
    {
        cout << "[ ";
        for (int i = top; i > -1; i--)
            cout << array[i] << ' ';

        cout << "]";
    }
};
