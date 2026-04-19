#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int item;
	Node* left;
	Node* right;
};

class Tree
{
	Node* root;
	int count;
	void PreOrderPrivate(Node* root);
	void PostOrderPrivate(Node* root);
	void InOrderPrivate(Node* root);
	Node* FindMaxPrivate(Node* root);
	Node* FindMinPrivate(Node* root);
	Node* DeletePrivate(int item, Node* r);

public:
	Tree()
	{
		root = NULL;
		count = 0;
	}
	bool IsEmpty()
	{
		return root == NULL;
	}
	void Insert(int element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		newNode->left = newNode->right = NULL;
		if (IsEmpty())
		{
			root = newNode;
		}
		else
		{
			Node* current = root;
			while (true)
			{
				if (current->item >= element)
				{
					if (current->left == NULL)
					{
						current->left = newNode;
						break;
					}
					else
						current = current->left;
				}
				else
				{
					if (current->right == NULL)
					{
						current->right = newNode;
						break;
					}
					else
						current = current->right;
				}
			}
		}
		count++;
	}

	void BreadthTraverse()
	{
		if (IsEmpty())
			return;
		queue<Node*> q;
		q.push(root);
		Node* temp;
		while (!q.empty())
		{
			temp = q.front();
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
			cout << temp->item << " ";
			q.pop();
		}
	}
	void PreOrder()
	{
		PreOrderPrivate(root);
	}
	void InOrder()
	{
		InOrderPrivate(root);
	}
	void PostOrder()
	{
		PostOrderPrivate(root);
	}
	//iterative
	int FindMax()
	{
		if (IsEmpty())
		{
			cout << "the Tree is Empty" << endl;
			return NULL;
		}
		Node* temp = root;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->item;
	}
	int FindMin()
	{
		if (IsEmpty())
		{
			cout << "the Tree is Empty" << endl;
			return NULL;
		}
		Node* temp = root;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp->item;
	}
	//recursion
	int FindMaxRecursion()
	{
		return FindMaxPrivate(root)->item;
	}
	int FindMinRecursion()
	{
		return FindMinPrivate(root)->item;
	}
	void Delete(int item)
	{
		root = DeletePrivate(item, root);
	}

};
Node* Tree::DeletePrivate(int item, Node* r)
{
	Node* temp;
	if (r == NULL)
	{
		cout << "the item you enter not exist" << endl;
		return NULL;
	}
	else if (r->item < item)
		r->right = DeletePrivate(item, r->right);
	else if (r->item > item)
		r->left = DeletePrivate(item, r->left);
	else
	{
		temp = r;
		if (r->left == NULL && r->right == NULL)
			r = NULL;
		else if (r->left == NULL)
			r = r->right;
		else if (r->right == NULL)
			r = r->left;
		else
		{
			Node* min = FindMinPrivate(r->right);
			r->item = min->item; 
			r->right = DeletePrivate(min->item, r->right);
			return r;
		}
		delete temp;
	}
	return r;
}
Node* Tree::FindMaxPrivate(Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL)
		return root;
	return FindMaxPrivate(root->right);
}
Node* Tree::FindMinPrivate(Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	return FindMinPrivate(root->left);
}
void Tree::PreOrderPrivate(Node* root)
{
	// root left right
	if (root == NULL)
		return;
	cout << root->item << " ";
	PreOrderPrivate(root->left);
	PreOrderPrivate(root->right);
}
void Tree::InOrderPrivate(Node* root)
{
	// left root right
	if (root == NULL)
		return;
	InOrderPrivate(root->left);
	cout << root->item << " ";
	InOrderPrivate(root->right);
}
void Tree::PostOrderPrivate(Node* root)
{
	// left right root
	if (root == NULL)
		return;
	PostOrderPrivate(root->left);
	PostOrderPrivate(root->right);
	cout << root->item << " ";
}

