#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int value;
	Node *right;
	Node *left;
	int height;
};

int height(Node *root)
{
	if (root == NULL)
		return -1;
	else
		return root->height;
}

int maxheight(int left, int right)
{
	if (left > right)
		return left;
	else
		return right;
}

Node* leftshift(Node *root)
{
	Node * temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = maxheight(height(root->left), height(root->right)) + 1;
	temp->height = maxheight(height(temp->left), root->height) + 1;
	return temp;

}

Node* rightshift(Node *root)
{
	Node * temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = maxheight(height(root->left), height(root->right)) + 1;
	temp->height = maxheight(height(temp->left), root->height) + 1;
	return temp;

}

Node * INSERT(Node *root, int value)
{
	if (root == NULL)
	{
		Node *temp = (Node*)malloc(sizeof(Node));
		temp->value = value;
		temp->left = NULL;
		temp->right = NULL;
		temp->height = 0;
		root = temp;
	}

	// new node on left... smaller than parent
	else if (root->value > value)
	{
		root->left = INSERT(root->left, value);
		if (height(root->left) - height(root->right) == 2)
		{
			if(value < root->left->value)
				//right shift
			root = rightshift(root);

			else
			{//rightleft shift
				root = leftshift(root);
				root = rightshift(root);
			}
		}
	}

	// new node on right.. bigger than parent
	else if (root->value < value)
	{
		root->right = INSERT(root->right, value);
		if (height(root->right) - height(root->left) == 2)
		{
			//left shift
			if (value > root->right->value)
			root = leftshift(root);
			else
			{   // right left shift
				root = leftshift(root);
				root = rightshift(root);
			}
		}

	}
	root->height = maxheight(height(root->left), height(root->right)) +1 ;
	return root;
}

void preorder(Node *root)
{
	if (root == NULL)
		return;
	cout << root->value << "\t";
	preorder(root->left);

	preorder(root->right);
}



int main()
{
	Node *root = NULL;
	root = INSERT(root, 135);
	root = INSERT(root, 120);
	root = INSERT(root, 30);
	root = INSERT(root, 60);
	root = INSERT(root, 20);
	root = INSERT(root, 18);
	root = INSERT(root, 75);
	root = INSERT(root, 87);
	root = INSERT(root, 56);
	root = INSERT(root, 93);
	root = INSERT(root, 150);
	root = INSERT(root, 22);
	root = INSERT(root, 69);
	preorder(root);

}
