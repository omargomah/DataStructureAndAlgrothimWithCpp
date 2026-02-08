#include <iostream>
using namespace std;

template <class t>
class Stack
{
private:
    struct Node
    {
        t item;
        Node *next;
    };
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void Push(t newItem)
    {
        Node *newNode = new Node;
        if (newNode == NULL)
            cout << "the memory is full  make space free to be able to push";
        else
        {
            newNode->item = newItem;
            newNode->next = top;
            top = newNode;
        }
    }
    void Pop()
    {
        if (IsEmpty())
            cout << "the stack is already empty";
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    t getTop()
    {
        if (IsEmpty())
            cout << "the Stack is empty";
        else
            return top->item;
        return -1;
    }
    bool IsEmpty()
    {
        return top == NULL;
    }
    void Display()
    {
        Node *temp = top;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << "]";
    }
};