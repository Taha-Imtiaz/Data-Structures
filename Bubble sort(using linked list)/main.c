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
struct node * search_previous(struct node *start,int element)
{
    int flag=0;
    struct node *curr= start;
    while(curr->next!= NULL)
    {
        if((curr->next)->value==element)
        {
            flag++;
            break;
        }
        curr= curr->next;
    }

    if(flag>0)
    {
       return curr;
    }
    else
    {
        //cout<<"\nThe value is not present in the list.\n";
        return NULL;
    }

}


struct node * search_current(struct node *start,int element)
{
    int flag=0;
    struct node *curr= start;
    while(curr!= NULL)
    {
        if(curr->value==element)
        {
            flag++;
            break;
        }
        curr= curr->next;
    }

    if(flag>0)
    {
       return curr;
    }
    else
    {
        //cout<<"\nThe value is not present in the list.\n";
        return NULL;
    }

}


void swap_nodes(int val1,int val2,struct node **start)
{



    struct node *p1=NULL;
    struct node *p2=NULL;
    struct node *prevp1= NULL;
    struct node *prevp2= NULL;
   struct node *temp= NULL;
    p1= search_current(*start,val1);
    prevp1= search_previous(*start,val1);
    p2= search_current(*start,val2);
    prevp2= search_previous(*start,val2);
    if(prevp1!=NULL)
    {
        prevp1->next= p2;
    }
    else
    {
        *start= p2;
    }

    if(prevp2!=NULL)
    {
        prevp2->next =p1;
    }
    else
    {
        *start= p1;
    }

  temp= p2->next;
  p2->next= p1->next;
  p1->next= temp;

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
int count_nodes(struct node *start)
{
    int count =0;
    struct node *curr=start;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
void bubble_sort(struct node **start)
{
    int count,i,j;
    struct node *curr=*start;
    count=count_nodes(*start);
    for(i=0;i<count;i++)
    {
        curr=*start;
        for(j=0;j<count-i;j++)
        {
            if(curr->value>(curr->next)->value)
            {
                swap_nodes(curr->value,(curr->next)->value,start);
            }
            else
            {
                curr=curr->next;
            }
        }
    }

}
int main()
{
struct node* start=NULL;
struct node *p1=NULL;
struct node *p2=NULL;
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
printf("\n\n");
swap_nodes(2,4,&start);
printlist(start);
printf("\n\n");

swap_nodes(1,3,&start);

//swaped(p1,p2,&start);
printlist(start);
printf("\n\n");
bubble_sort(&start);
printlist(start);
}


