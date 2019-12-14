#include <stdlib.h>
#include <iostream>
using namespace std;


struct Node
{
	int value;
	Node *child;
	Node *next;
};

void Insert(Node **root,Node **parent,int value)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->child = NULL;
	temp->next = NULL;

	if (*root == NULL) {
		*root = temp;
	}

	else
	{


		if ((*parent)->child == NULL)
		{
			(*parent)->child = temp;
		}


		else
		{
			Node *curr = (*parent)->child;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
}

int main()
{
	Node *root = NULL;
	Insert(&root,&root ,1);
	Insert(&root, &root, 3);
	Insert(&root, &(root->child), 2);
	Insert(&root, &(root), 4);
	Insert(&root, &(root->child->next), 7);


	cout << root->value<<endl;
	cout << root->child->value<<endl;
	cout << root->child->child->value<<endl;
	cout << root->child->next->value<<endl;
	cout << root->child->next->child->value<<endl;
}
