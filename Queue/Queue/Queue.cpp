#include<iostream>
using namespace std;
struct node
{
int value;
struct node *next;

};
void Enqueue(struct node **front,struct node **rear,int element)
{
	struct node *ptr;
ptr= (struct node*)malloc(sizeof(struct node));
ptr->value= element;
    ptr->next= NULL;
if(*front==NULL&&*rear==NULL)
{
  
    cout<<"\nEnqueued element is "<<element<<".\n\n";
    
    *front = ptr;
    *rear= ptr; 
}
else
{
	(*rear)->next=ptr;
	*rear=ptr;

}
}
void Dequeue(struct node **front,struct node **rear)
{

if(*front==NULL)
{
*front=*rear;
}
if(*front!=NULL)
{
struct node *temp;
temp=*front;
cout<<(*front)->value<< "Is Dequeued"<<endl;
*front=(*front)->next;
free(temp);
}
else
	cout<<"Queue is Empty";
}
void display_Queue(struct node *front)
{
	struct node *temp=front;
	while(temp!=NULL)
	{
		cout<<temp->value;
		temp=temp->next;
	}
}
int main()
{
	struct node *front;
	struct node *rear;
	Enqueue(&front,&rear,5);
	Enqueue(&front,&rear,10);
	Enqueue(&front,&rear,15);
	Enqueue(&front,&rear,20);
	Enqueue(&front,&rear,25);
	Enqueue(&front,&rear,30);
	display_Queue(front);
	Dequeue(&front,&rear);
	Dequeue(&front,&rear);
	Dequeue(&front,&rear);
	Dequeue(&front,&rear);
	Dequeue(&front,&rear);
	display_Queue(front);
	system("pause");
}