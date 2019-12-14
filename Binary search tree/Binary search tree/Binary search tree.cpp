
#include <stdlib.h>
#include<iostream>
using namespace std;
struct node{
int data;
struct node *left;
struct node *right;

};


void insert_node(struct node **root);
void decide(struct node *curr,struct node *ptr);
void search(struct node *root,int value,int flag);


void insert_node(struct node **root)
{
    struct node *ptr;
    int num=0;
    ptr=(struct node*)malloc(sizeof(struct node));
  cout<<"enter number";
  cin>>num;
  ptr->data=num;
  ptr->left=NULL;
  ptr->right=NULL;

  if(*root==NULL)
     {
       *root=ptr;

    }
  else
    {
    struct node *curr=*root;
     decide(curr,ptr);

   }

}


void decide(struct node *curr,struct node *ptr)
{
    if((ptr->data)<curr->data)
    {
        if((curr->left)==NULL)
        {
            curr->left=ptr;
        }
        else
            curr=curr->left;
            decide(curr,ptr);
    }

    else if((ptr->data)>curr->data)
    {
         if((curr->right)==NULL)
        {
            curr->right=ptr;
        }
        else
            curr=curr->right;
            decide(curr,ptr);
    }
}

void search(struct node *root,int value,int flag)
{

    if(root==NULL)
    {
        cout<<"no such value exists";
    }


    else if(value==root->data)
    {
        if(flag==0)
          cout<<root->data<<" found at root";

        else if(flag==1)
          cout<<root->data<<" found at right";

         else if(flag==2)
         cout<<root->data<<" found at left";
    }

  else if(value>root->data)
        {
            root=root->right;
            flag=1;
            search(root,value,flag);
        }




    else if(value<root->data)
        {

            root=root->left;
            flag=2;
            search(root,value,flag);
        }

}
/*struct node* DeleteNode(struct node **root,int value)
{

	if(*root==NULL)
    {
        cout<<"no such value exists";
    }
else if((*root)->data==value)
	if((*root)->left==NULL&&(*root)->right==NULL)
	{

	}
{
	if((*root)->left!=NULL&&(*root)->right==NULL)
	{
		struct node  *curr=*root;
		*root=(*root)->left;
		delete (curr);
	}
}

if(value<(*root)->data)
{

	*root=(*root)->left;
(*root)->left=	DeleteNode(&(*root),value);
}
if(value>(*root)->data)
{

	*root=(*root)->right;
	(*root)->right=DeleteNode(&(*root),value);
}
return
}*/
int main()
{
    struct node* start=NULL;
	int value;
        insert_node(&start);
    insert_node(&start);
    insert_node(&start);
    insert_node(&start);
    insert_node(&start);
    insert_node(&start);
	cout<<"Enter the value to be searched ";
	cin>>value;
    search(start,value,0);
	cout<<endl;
cout<<"Enter the value to be searched ";
	cin>>value;
    search(start,value,0);
	system("pause");

}
