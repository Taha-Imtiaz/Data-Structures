#include<stdlib.h>
#include <iostream>

using namespace std;
//BSTNode* InsretNode(struct BSTNode **,int);
struct BSTNode
{
	int data;
	struct BSTNode *LeftChild;
	struct BSTNode *RightChild;
};
BSTNode* InsertNode(struct BSTNode **root,int data)
{
struct BSTNode *ptr;
ptr=(struct BSTNode*)malloc(sizeof(struct BSTNode));
ptr->data=data;
//cout<<ptr->data<<endl;
ptr->LeftChild=NULL;
ptr->RightChild=NULL;

if(*root=NULL)
	{
		*root=ptr;
    }
    else

    if(data<(*root)->data)
    {

    (*root)->LeftChild=InsertNode(&((*root)->LeftChild),data);
	//cout<<curr->LeftChild<<"is found at left";
//	curr=curr->LeftChild;
    }
     if(data>(*root)->data)
    {

   (*root)->RightChild=InsertNode(&((*root)->RightChild),data);
	//cout<<curr->data<<"is found at right";
	//curr=curr->RightChild;
    }
    return *root;
    }



int main()
{
	struct BSTNode *root =NULL;
	InsertNode(&root,80);
	InsertNode(&root,75);
	InsertNode(&root,65);
	InsertNode(&root,55);
	InsertNode(&root,105);
	InsertNode(&root,175);
	InsertNode(&root,715);

	system("pause");
}
