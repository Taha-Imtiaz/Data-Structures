#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
void push_value(struct node **top,int element)
{

    struct node *ptr;

    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->value=element;
    printf("Pushed value is %d\n",element);
    ptr->next=*top;
      *top=ptr;


}
void pop_value(struct node **top)
{
    if(*top==NULL)
    {
        printf("\nStack is underflow");
    }
   if(*top!=NULL)
    {


     struct node *temp;
    temp=*top;
    (*top)=(*top)->next;
    printf("%d has popped\n",temp->value);
    free(temp);
}
}
void peek_stack(struct node *start)
{
    struct node *curr=start;
    printf("The Elements in a stack are\n");
    while(curr!=NULL)
    {
        printf("%d\n",curr->value);
        curr=curr->next;
    }
}
void main()
{
    struct node *top=NULL;
    push_value(&top,5);
    push_value(&top,4);
    push_value(&top,3);
    push_value(&top,2);
    push_value(&top,1);
    push_value(&top,0);
    peek_stack(top);
    pop_value(&top);
     pop_value(&top);
      pop_value(&top);
     pop_value(&top);

      pop_value(&top);
     pop_value(&top);

      pop_value(&top);
     pop_value(&top);



}
