#include <stdio.h>
#include <stdlib.h>
struct node
{
int value;
struct node *next;
};





void insert(struct node **mystart)

{

    struct node *ptr;
    int input;
   ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value");
    scanf("%d",&input);
    ptr->value=input;
    ptr->next=NULL;
    if(*mystart==NULL)
    {
        *mystart=ptr;

    }
    else
    {
    struct node * curr=*mystart;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
         curr->next=ptr;
    }


}
void printlist(struct node *mystart)

{
  struct node * curr=mystart;
    while(curr->next!=NULL)
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

     while(curr!=NULL)
    {
       if(searchElement==curr->value)
       {
           printf("Element found\n");
           break;
       }

 curr=curr->next;

    }

}
void deleteElement(struct node **mystart)
{
    int deleteElement;

    struct node * curr=*mystart;
    printf("Enter a number you want to delete");
    scanf("%d",&deleteElement);


       if(deleteElement==(*mystart)->value)
       {
           *mystart=(*mystart)->next;
           free(curr);
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
struct node* FindMinNode(struct node **mystart)
{
    struct node *min=*mystart;
    struct node *curr=(*mystart)->next;

    while(curr!=NULL)
    {
        if(curr->value<min->value)
        {

                min=curr;
        }
        curr=curr->next;
    }
    return min;
}
int main()
{
struct node* start=NULL;
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
printf("\n\n\n");
struct node * min=FindMinNode(&start);
printf("Min node is %d\n",(*min));
printlist(start);
}

