#include <iostream>
#include <queue>
using namespace std;

///  0 1 1 2 3 


// 1  ---> 1 + 2*3 + 4*5*6 + 7*8*9*10

/*int Product(int s, int end)
{
	if (s == end)
		return s;
	return end * Product(s,end - 1);
}
int fun(int n, int start = 1)
{
	if (n == 0)
		return 1;
	return start + Product()
}*/




struct Node
{
	int item;
	Node* Left;
	Node* Right;
};
class BinarySearchTree
{
	Node* Root;
	int count;
	Node* Delete(Node* r, int item);
	Node* GetMax(Node* r);
	Node* GetMin(Node* r);
	void PreOrder_DFS(Node* r);
	void PostOrder_DFS(Node* r);
	void InOrder_DFS(Node* r);
public:
	BinarySearchTree()
	{
		Root = NULL;
		count = 0;
	}
	bool IsEmpty()
	{
		return Root == NULL;
	}
	void Insert(int item)
	{
		Node* NewNode = new Node ,* prev  = NULL,* cur = Root;
		NewNode->item = item;
		NewNode->Left = NewNode->Right = NULL;
		while (cur != NULL)
		{
			prev = cur;
			if (cur->item > item)
				cur = cur->Left;
			else
				cur = cur->Right;
		}
		if (prev == NULL)
			Root = NewNode;
		else if(prev->item > item)
			prev->Left = NewNode;
		else
			prev->Right = NewNode;
		count++;
	}

	void Delete(int item)
	{
		if (IsEmpty())
			return;

		Root = Delete(Root, item);
		count--;
	}

	int GetMaxValue()
	{
		return GetMax(Root)->item;
	}

	int GetMinValue()
	{
		return GetMin(Root)->item;
	}
	bool Search(int item)
	{
		Node* cur = Root;
		while (cur != NULL)
		{
			if (cur->item > item)
				cur = cur->Left;
			else if (cur->item < item)
				cur = cur->Right;
			else
				return true;
		}
		return false;
	}
	void BFS()
	{
		if (IsEmpty())
			return;
		queue<Node*> q;
		q.push(Root);
		Node* temp;
		while (!q.empty())
		{
			temp = q.front();
			if (temp->Left != NULL)
				q.push(temp->Left);
			if (temp->Right != NULL)
				q.push(temp->Right);
			cout << temp->item << " ";
			q.pop();
		}
		cout << endl;
	}

	void PreOrder_DFS()
	{
		PreOrder_DFS(Root);
	}

	void PostOrder_DFS()
	{
		PostOrder_DFS(Root);
	}

	void InOrder_DFS()
	{
		InOrder_DFS(Root);
	}
};
void BinarySearchTree::PreOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	cout << r->item << " ";
	PreOrder_DFS(r->Left);
	PreOrder_DFS(r->Right);
}
void BinarySearchTree::PostOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	PostOrder_DFS(r->Left);
	PostOrder_DFS(r->Right);
	cout << r->item << " ";
}
void BinarySearchTree::InOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	InOrder_DFS(r->Left);
	cout << r->item << " ";
	InOrder_DFS(r->Right);
}
Node* BinarySearchTree::GetMax(Node* r) 
{
	if (r->Right == NULL)
		return r;
	return GetMax(r->Right);
}
Node* BinarySearchTree::GetMin(Node* r)
{
	if (r->Left == NULL)
		return r;
	return GetMin(r->Left);
}
Node* BinarySearchTree::Delete(Node* r,int item)
{
	if (r == NULL)
	{
		cout << "the item not exit" << endl;
		return NULL;
	}
	if (r->item > item)
		r->Left = Delete(r->Left, item);
	else if (r->item < item)
		r->Right = Delete(r->Right, item);
	else
	{
		Node* nodeWillDelete = r;
		if (r->Left == NULL && r->Right == NULL)
			r = NULL;
		else if(r->Left == NULL )
			r = r->Right;
		else if(r->Right == NULL )
			r = r->Left;
		else 
		{
			Node* min = GetMin(r->Right);
			r->item = min->item;		
			r->Right = Delete(r->Right,r->item);
			return r;
		}
		delete nodeWillDelete;
	}
	return r;
}

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
}