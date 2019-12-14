#include <stdio.h>
#include <stdlib.h>

struct node
{
int value;
struct node *next;
};


struct node* start=NULL;


void insert()

{

    struct node *ptr;
    int input;
   ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter a value");
    scanf("%d",&input);
    ptr->value=input;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;

    }
    else
    {
struct node * curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
         curr->next=ptr;
    }


}
void printlist()

{
  struct node * curr=start;
    while(curr->next!=NULL)
    {
        printf("%d\n",curr->value);
         curr=curr->next;

    }
 printf("%d\n",curr->value);
}

void searchElement()
{
    int searchElement;
    struct node * curr=start;
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
void deleteElement()
{
    int deleteElement;

    struct node * curr=start;
    printf("Enter a number you want to delete");
    scanf("%d",&deleteElement);


       if(deleteElement==start->value)
       {
           start=start->next;
           free(curr);
       }
       else
       {
           struct node *prev=start;
           struct node *curr=start->next;


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
insert();
insert();
insert();
insert();
insert();
insert();
printlist();
searchElement();
deleteElement();
printlist();
}
