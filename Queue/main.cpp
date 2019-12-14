
#include<stdlib.h>

#include<iostream>
using namespace std;
struct node
{
int value;
struct node *next;

};
void Enqueue(struct node **Front,struct node **rear,int element)
{
	struct node *ptr;
ptr= (struct node*)malloc(sizeof(struct node));
ptr->value= element;
    ptr->next= NULL;
if(*Front==NULL)
{

    cout<<"\nEnqueued element is "<<element<<".\n\n";

    *Front = ptr;
    *rear= ptr;
}
else
     cout<<"\nEnqueued element is "<<element<<".\n\n";
{
	(*rear)->next=ptr;
	*rear=ptr;

}
}
void Dequeue(struct node **Front,struct node **rear)
{
struct node *temp;
if(*Front==NULL)
{
*Front=*rear;
}
if(*Front!=NULL)
{

temp=*Front;
cout<<endl<<(*Front)->value<< " Is Dequeued"<<endl;
*Front=(*Front)->next;
free(temp);
}
else
	cout<<"Queue is Empty";
}
void display_Queue(struct node *Front)
{
	struct node *temp=Front;
	while(temp!=NULL)
	{
		cout<<temp->value<<endl;
		temp=temp->next;
	}
}
int main()
{
	struct node *Front=NULL;
	struct node *rear=NULL;
	Enqueue(&Front,&rear,5);
	Enqueue(&Front,&rear,10);
	Enqueue(&Front,&rear,15);
	Enqueue(&Front,&rear,20);
	Enqueue(&Front,&rear,25);
	Enqueue(&Front,&rear,30);
	display_Queue(Front);
	Dequeue(&Front,&rear);
	Dequeue(&Front,&rear);
	Dequeue(&Front,&rear);
	Dequeue(&Front,&rear);
	Dequeue(&Front,&rear);
	Dequeue(&Front,&rear);


	display_Queue(Front);

	system("pause");
}
