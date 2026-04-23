#include <iostream>
#include <queue>
using namespace std;




struct Node
{
	int item;
	Node* Left;
	Node* Right;
};
class AVLTree
{
	Node* Root;
	int count;
	Node* Insert(Node* r, int item);
	Node* Delete(Node* r, int item);
	Node* GetMax(Node* r);
	Node* GetMin(Node* r);
	int BalanceFactor(Node* r);
	int UpdateHeight(Node* r);
	Node* RightRotation(Node* r);
	Node* LeftRotation(Node* r);
	void PreOrder_DFS(Node* r);
	void PostOrder_DFS(Node* r);
	void InOrder_DFS(Node* r);
public:
	AVLTree()
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
		Root = Insert(Root, item);
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
Node* AVLTree::Insert(Node* r, int item)
{
	if (r == NULL)
	{
		Node* NewNode = new Node;
		NewNode->item = item;
		NewNode->Left = NewNode->Right = NULL;
		r = NewNode;
	}
	else if (r->item > item)
		r->Left = Insert(r->Left, item);
	else
		r->Right = Insert(r->Right, item);
	if (BalanceFactor(r) == 2)
	{
		if (BalanceFactor(r->Left) == -1)
			r->Left = LeftRotation(r->Left);
		r = RightRotation(r);
	}
	else if (BalanceFactor(r) == -2)
	{
		if (BalanceFactor(r->Right) == 1)
			r->Right = RightRotation(r->Right);
		r = LeftRotation(r);

	}
	return r;
}
int AVLTree::BalanceFactor(Node* r)
{
	if (r == NULL)
		return 0;
	return UpdateHeight(r->Left) - UpdateHeight(r->Right);
}
int AVLTree::UpdateHeight(Node* r)
{
	if (r == NULL)
		return -1;
	int leftHeight = UpdateHeight(r->Left);
	int RightHeight = UpdateHeight(r->Right);
	return max(leftHeight, RightHeight) + 1;
}
Node* AVLTree::RightRotation(Node* r)
{
	Node* q = r->Left;
	r->Left = q->Right;
	q->Right = r;
	return q;
}
Node* AVLTree::LeftRotation(Node* r)
{
	Node* q = r->Right;
	r->Right = q->Left;
	q->Left = r;
	return q;
}
void AVLTree::PreOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	cout << r->item << " ";
	PreOrder_DFS(r->Left);
	PreOrder_DFS(r->Right);
}
void AVLTree::PostOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	PostOrder_DFS(r->Left);
	PostOrder_DFS(r->Right);
	cout << r->item << " ";
}
void AVLTree::InOrder_DFS(Node* r)
{
	if (r == NULL)
		return;
	InOrder_DFS(r->Left);
	cout << r->item << " ";
	InOrder_DFS(r->Right);
}
Node* AVLTree::GetMax(Node* r)
{
	if (r->Right == NULL)
		return r;
	return GetMax(r->Right);
}
Node* AVLTree::GetMin(Node* r)
{
	if (r->Left == NULL)
		return r;
	return GetMin(r->Left);
}
Node* AVLTree::Delete(Node* r, int item)
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
		else if (r->Left == NULL)
			r = r->Right;
		else if (r->Right == NULL)
			r = r->Left;
		else
		{
			Node* min = GetMin(r->Right);
			r->item = min->item;
			r->Right = Delete(r->Right, r->item);
			return r;
		}
		delete nodeWillDelete;
	}
	if (BalanceFactor(r) == 2)
	{
		if (BalanceFactor(r->Left) == -1)
			r->Left = LeftRotation(r->Left);
		r = RightRotation(r);
	}
	else if (BalanceFactor(r) == -2)
	{
		if (BalanceFactor(r->Right) == 1)
			r->Right = RightRotation(r->Right);
		r = LeftRotation(r);
	}
	return r;
}
