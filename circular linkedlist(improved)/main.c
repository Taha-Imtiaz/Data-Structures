#include <stdio.h>
#include <stdlib.h>
struct node
{
int value;
struct node *next;
};




void insert(struct node **mystart)

{

    struct node *ptr,*last;
    int input;
   ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value");
    scanf("%d",&input);
    ptr->value=input;
    ptr->next=NULL;

    if(*mystart==NULL)
    {
        *mystart=ptr;
        last=ptr;
        last->next=*mystart;

    }
    else if(*mystart!=NULL) //inserting node at beginning
    {
        ptr->next=*mystart;
        *mystart=ptr;
        last->next=*mystart;
    }
    else
    {
    struct node * curr=*mystart,*last;
       last->next=ptr;
       last=ptr;
       last->next=*mystart;
    }


}
void printlist(struct node *mystart)

{
  struct node * curr=mystart;

    while(curr->next!=mystart)
    {
        printf("%d\n",curr->value);
         curr=curr->next;

    }
 printf("%d\n",curr->value);
}

void searchElement(struct node *mystart)
{
    int searchElement;
    struct node * curr=mystart;
    printf("Enter a number you want to search");
    scanf("%d",&searchElement);

     while(curr->next!=mystart)
    {
       if(searchElement==curr->value)
       {
           printf("Element found is %d\n",curr->value);
           break;
       }

 curr=curr->next;

    }
  if(searchElement!=curr->value)
    {
        printf("%d is not found\n",searchElement);
    }

}
void deleteElement(struct node **mystart)
{
    int deleteElement;
    struct node *last;

    struct node * curr=*mystart;
    printf("Enter a number you want to delete");
    scanf("%d",&deleteElement);


       if(deleteElement==(*mystart)->value)
       {
           *mystart=(*mystart)->next;
           free(curr);
           last->next=*mystart;
       }
       else
       {
           struct node *prev=*mystart;
           struct node *curr=(*mystart)->next;


 while(curr->value!=deleteElement)
    {
         curr=curr->next;
         prev=prev->next;

    }
    prev->next=curr->next;
    free(curr);
}
}
int main()
{
struct node* start=NULL;
int choice,value,choice1;
printf("Do you want to perform the following operations in linked list\n");
printf("1.Insert\n2.Delete\n3.display\n4.search\n5.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
    {
        printf("Enter the value to be inserted\n");
        scanf("%d",&value);
        while(1)
        {
            printf("Select one the following inserting options\n");
            printf("1.Insertion at the beginning\n2.Insertion at the end\n3.Exit\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
            case 1:
                insert_at_begining();
                break;
            }

        }
    }
}
insert(&start);
insert(&start);
insert(&start);
insert(&start);
insert(&start);
insert(&start);
printlist(start);
searchElement(start);
deleteElement(&start);
printlist(start);
}

