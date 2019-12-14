#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *prev;
    struct node *next;
};
void insert_value(struct node **mystart)
{
int input;
struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
printf("Enter the value you want to insert");
scanf("%d",&input);
ptr->value=input;
ptr->prev=NULL;
ptr->next=NULL;
if(*mystart==NULL)
{
    *mystart=ptr;
    ptr->prev=NULL;
   ptr->next=NULL;

}
else
{
    struct node * curr=*mystart;
        while(curr->next!=NULL)
        {
        curr=curr->next;
        }
        curr->next=ptr;
        ptr->prev=curr;

}
}
void print_list(struct node *mystart)
{
    struct node * curr=mystart;
    printf("List Elements are\n");
    while(curr->next!=NULL)
    {
    printf("%d\n",curr->value);
    curr=curr->next;
    }
     printf("%d",curr->value);
}
void search_list(struct node *mystart)
{
    int search_node;
    struct node * curr=mystart;
    printf("\nEnter a node you want to search in a list");
    scanf("%d",&search_node);
    while(curr!=NULL)
    {
    if(curr->value==search_node)
    {
        printf("%d is found successfully",curr->value);
        break;

    }
    curr=curr->next;
    }
if(curr->value!=search_node)
printf("%d is not in the list",search_node);
}


void insertion_Sort(struct node **start)
{
    struct node *curr=(*start)->next;
    while(curr!=NULL)
    {
        int hold=curr->value;
        struct node *temp=curr;
        //hold->value=curr->value;
        while(hold<(temp->prev)->value)
        {

            temp->value=(temp->prev)->value;
            temp=temp->prev;
             if(temp->prev==NULL)
           {

            break;

           }

        }
        temp->value=hold;
        curr=curr->next;
    }
}


/*void insertion_Sort(struct node **start)
{
	struct node *curr = (*start)->next;
	while(curr != NULL)
	{
		int hold = curr->value;
		struct node *temp = curr;
		while(hold < (temp->prev)->value)
		{
			temp->value = (temp->prev)->value;
			temp = temp->prev;
			if(temp->prev == NULL)
			{
				break;
			}
		}
		temp->value = hold;
		curr = curr->next;
	}
}*/
void delete_node(struct node **mystart)
{
    struct node *curr=*mystart;
    int delete_element;
    printf("\nEnter a node you want to delete\n");
    scanf("%d",&delete_element);
    if((*mystart)->value==delete_element)
    {
        *mystart=(*mystart)->next;
        (*mystart)->prev=NULL;
        free(curr);
    }
    else{

         struct node *curr=(*mystart)->next;


         while(curr->next!=NULL)
         {
            if(curr->value==delete_element)
             {
               (curr->prev)->next=curr->next;
               (curr->next)->prev=curr->prev;
             free(curr);
             }
        curr=curr->next;

    }

if(curr->next==NULL)
    {
     if(curr->value==delete_element)
             {
        (curr->prev)->next=NULL;
         free(curr);
    }
}
    }

}

main()
{
    struct node *start=NULL;
    insert_value(&start);
    insert_value(&start);
    insert_value(&start);
    insert_value(&start);
    insert_value(&start);
    insert_value(&start);
    insert_value(&start);
    print_list(start);
    search_list(start);
    delete_node(&start);
    print_list(start);
printf("\n");
insertion_Sort(&start);
print_list(start);
}
