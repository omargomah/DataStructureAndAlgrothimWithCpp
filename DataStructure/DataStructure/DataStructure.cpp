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
	void PreOrder(Node* root);
	void PostOrder(Node* root);
	void InOrder(Node* root);
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
		if (IsEmpty)
		{
			root = newNode;
		}
		else
		{
			Node* current = root;
			while(true)
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
						current->right= newNode;
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
		PreOrder(root);
	}
	void InOrder()
	{
		InOrder(root);
	}
	void PostOrder()
	{
		PostOrder(root);
	}
};
void Tree::PreOrder(Node* root)
{
	// root left right
	if (root == NULL)
		return;
	cout << root->item << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void Tree::InOrder(Node* root)
{
	// left root right
	if (root == NULL)
		return;
	PreOrder(root->left);
	cout << root->item << " ";
	PreOrder(root->right);
}
void Tree::PostOrder(Node* root)
{
	// left right root
	if (root == NULL)
		return;
	PreOrder(root->left);
	PreOrder(root->right);
	cout << root->item << " ";
}
int main()
{

}