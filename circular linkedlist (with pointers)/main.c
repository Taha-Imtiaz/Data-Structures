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
   /* else if(*mystart!=NULL) //inserting node at beginning
    {
        ptr->next=*mystart;
        *mystart=ptr;
        last->next=*mystart;
    }*/
    else
    {
    struct node * curr=*mystart;
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
    if(curr->next==mystart)
 {
      if(searchElement==curr->value)
       {
           printf("Element found is %d\n",curr->value);

       }
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
    //int flag=0;

    struct node * curr=*mystart;
    printf("Enter a number you want to delete");
    scanf("%d",&deleteElement);


       if(deleteElement==(*mystart)->value)
       {
           *mystart=(*mystart)->next;
           free(curr);
           last->next=*mystart;
       }

  else if(curr->next!=*mystart)
  {
      int flag=0;
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
else
{
  struct node *prev=*mystart;
    struct node *curr=(*mystart)->next;
   while(curr->value!=deleteElement)
    {
         curr=curr->next;
         prev=prev->next;

    }

    prev->next=*mystart;
     free(curr);

}
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
}

