\
#include <iostream>
#include<stdlib.h>
using namespace std;

struct vertex
{
    struct vertex *down=NULL;
    struct edge *head=NULL;
    char value;
    int status;
    bool done;
};

struct edge
{
    struct vertex *temp=NULL;
    struct edge *next=NULL;
    int weight=20;
};

struct krushkal{

char first;
char second;
int weight;
struct krushkal *next=NULL;

};

struct stackk
{
    char value;
    struct stackk *next=NULL;
};

void addvertex(struct vertex **start);
void addedge(struct vertex **start);
void addvertex_krushkal(struct vertex **krushkal,char *a);
void addedge_krushkal(struct vertex **krushkal,char first,char second,int weight);
void delete_edge_khuskal(struct vertex **krushkal,char first,char second);

void display(struct vertex *start);
void find_edge(struct vertex *start,struct krushkal **mini);
void khuskal(struct vertex *start,struct vertex **krushkal);
void original_status(struct vertex **krushkal);
char pop(struct stackk **top);
void push(struct vertex **node,struct stackk **top);
void iscycle(struct vertex **krushkal);
void swap_values(struct krushkal *a, struct krushkal *b);
void bubble_sort(struct krushkal **start);





int main()
{
    struct vertex *start=NULL;
    struct vertex *Krushkal=NULL;

    addvertex(&start);
    addvertex(&start);
    addvertex(&start);
    addvertex(&start);



    addedge(&start);
    addedge(&start);
    addedge(&start);
    addedge(&start);
    addedge(&start);

    display(start);

    khuskal(start,&Krushkal);

    cout<<"\n\n";

    display(Krushkal);


}

void addvertex(struct vertex **start)
{
    struct vertex *ptr=NULL;
    ptr=new(vertex);
    cout<<"Enter node";
    cin>>ptr->value;
    ptr->down=NULL;
    ptr->head=NULL;
    ptr->status=1;
    ptr->done=false;

    if(*start==NULL)
    {
        *start=ptr;
    }

    else
    {
        struct vertex *curr=*start;
        while(curr->down!=NULL)
        {
            curr=curr->down;
        }

        curr->down=ptr;
    }
}


void addedge(struct vertex **start)
{
     struct edge *ptr=new(edge);
    struct vertex *curr=*start;
    struct vertex *curri=*start;
    char first,second;
    int weight=0;
    cout<<"Enter first and second vertex";
    cin>>first;
    cin>>second;
    cout<<"Enter weight for this edge";
    cin>>weight;

    while(curr->value!=first)
    {
        curr=curr->down;
    }

    while(curri->value!=second)
    {
        curri=curri->down;
    }

    if(curr==NULL || curri==NULL)
    {
        cout<<"Wrong input";
        return;
    }

    else{
        ptr->temp=curri;
       if(curr->head==NULL)
       {
           curr->head=ptr;
           (curr->head)->weight=weight;
       }
       else
       {
           struct edge *alpha=curr->head;
           while(alpha->next!=NULL)
           {
               alpha=alpha->next;
           }
           alpha->next=ptr;
           (alpha->next)->weight=weight;
       }


    }
}


void addvertex_krushkal(struct vertex **krushkal,char a)
{
    struct vertex *temp=*krushkal;
    while(temp!=NULL)
    {
      if(temp->value==a)
      {
          return;
      }
      temp=temp->down;
    }

    struct vertex *ptr=NULL;
    ptr=new(vertex);
    ptr->value=a;
    ptr->down=NULL;
    ptr->head=NULL;
    ptr->status=1;
    ptr->done=false;

    if(*krushkal==NULL)
    {
        *krushkal=ptr;
    }

    else
    {
        struct vertex *curr=*krushkal;
        while(curr->down!=NULL)
        {
            curr=curr->down;
        }

        curr->down=ptr;
    }
}



void addedge_krushkal(struct vertex **krushkal,char first,char second,int weight)
{
     struct edge *ptr=new(edge);
    struct vertex *curr=*krushkal;
    struct vertex *curri=*krushkal;

    while(curr->value!=first)
    {
        curr=curr->down;
    }

    while(curri->value!=second)
    {
        curri=curri->down;
    }

    if(curr==NULL || curri==NULL)
    {
        cout<<"Wrong input";
        return;
    }

    else{
        ptr->temp=curri;
       if(curr->head==NULL)
       {
           curr->head=ptr;
           (curr->head)->weight=weight;
       }
       else
       {
           struct edge *alpha=curr->head;
           while(alpha->next!=NULL)
           {
               alpha=alpha->next;
           }
           alpha->next=ptr;
           (alpha->next)->weight=weight;
       }


    }
}



void delete_edge_khuskal(struct vertex **krushkal,char first,char second)
{

    struct vertex *curr=*krushkal;
    struct vertex *curri=*krushkal;

    while(curr->value!=first)
    {
        curr=curr->down;
    }

    while(curri->value!=second)
    {
        curri=curri->down;
    }

    if(curr==NULL || curri==NULL)
    {
        cout<<"Wrong input";
        return;
    }

     else
     {
         if((curr->head)->temp==curri)
         {
             struct edge *tempo=curr->head;
             curr->head=(curr->head)->next;
             free(tempo);

         }

         else
         {
             struct edge *tempo=curr->head;
             while((tempo->next)->temp!=curri)
             {
                 tempo=tempo->next;
             }
            struct edge *flag=tempo->next;
            tempo->next=flag->next;
            free(flag);
         }

     }
}

void iscycle(struct vertex **Krushkal)
{

struct vertex *curr=*Krushkal;
 struct edge *curre=NULL;
 struct stackk *top=NULL;
 int i=0;
 push(&curr,&top);

 while(top!=NULL)
 {

 L1:
     if(curre==NULL)
     {
     curre=curr->head;
     }

     else
     {
         curr=*Krushkal;
         while(curr->value!=(curre->temp)->value)
         {
             curr=curr->down;
         }
              curre=curr->head;
     }

     while(curre!=NULL)
     {
         int i=0;
         if((curre->temp)->status==2)
         {
             char a=(curre->temp)->value;
             curre=curre->next;
             delete_edge_khuskal(Krushkal,curr->value,a);
             i++;
         }


             if(i==0)
             {

          if((curre->temp)->status==1)
         {
             push(&(curre->temp),&top);
             //cout<<(curre->temp)->value;
             break;
         }

          curre=curre->next;
     }

     }


  if(curre==NULL)
    {
      char a;
      bool temp=true;
      curr->done=true;

      if(top!=NULL)
      {
      a=pop(&top);
      while(temp)
      {
          curr=*Krushkal;
          while(curr->value!=a)
          {
            curr=curr->down;
          }

          if(curr->done)
          {
              curr->status=3;
              a=pop(&top);
          }

          else{

            temp=false;
            curr->status=3;
          }
      }

      if(top==NULL)
      {
      goto L1;
      }

    }

   }

}

 original_status(Krushkal);

}



void push(struct vertex **node,struct stackk **top)
{
    struct stackk *ptr=new(stackk);
    ptr->value=(*node)->value;
    (*node)->status=2;
    ptr->next=NULL;

    if(*top==NULL)
    {
        *top=ptr;
    }
    else
    {
        ptr->next=*top;
       *top=ptr;
    }
}

char pop(struct stackk **top)
{
    struct stackk *temp=NULL;

    if(*top==NULL)
    {
        cout<<"No element exists";
    }

    else
    {
         temp=*top;
         char a=temp->value;
         *top=(*top)->next;
         free(temp);
         return(a);
    }

}


void original_status(struct vertex **krushkal)
{
   struct vertex *curr=*krushkal;
   while(curr!=NULL)
   {
    curr->status=1;
    curr->done=false;
    curr=curr->down;
   }
}

void bubble_sort(struct krushkal **start)
{
    struct krushkal *curr=*start;
    struct krushkal *curri = NULL;

        while (curr->next!= NULL)
        {
            curri=curr->next;
            while(curri!=NULL)
            {

            if (curr->weight > curri->weight)
            {
                swap_values(curr, curri);
                //cond=true;
            }
            curri=curri->next;
            }
            curr = curr->next;
        }

}

void swap_values(struct krushkal *a, struct krushkal *b)
{
    int weight=0;
    weight= a->weight;
    a->weight = b->weight;
    b->weight = weight;

    char first;
     first= a->first;
    a->first = b->first;
    b->first = first;


    char second;
     second= a->second;
    a->second = b->second;
    b->second = second;

}

void khuskal(struct vertex *start,struct vertex **krushkal)
{
    struct krushkal *mini=NULL;
    find_edge(start,&mini);
    bubble_sort(&mini);


    while(mini!=NULL)
    {

    addvertex_krushkal(krushkal,mini->first);
    addvertex_krushkal(krushkal,mini->second);

    addedge_krushkal(krushkal,mini->first,mini->second,mini->weight);

    mini=mini->next;

    }

    iscycle(krushkal);
}

void find_edge(struct vertex *start,struct krushkal **mini)
{
    int flag=0;
    while(start!=NULL)
    {
        struct edge *curr=start->head;
        //struct vertex *first=*krushkal;
        while(curr!=NULL)
        {
          /*  while(first!=NULL)
            {
                struct edge *temp=first->head;
                while(temp!=NULL)
                {
                    if(temp==curr)
                    {
                        flag++;
                        break;
                    }
                    temp=temp->next;
                }
                if(flag!=0)
                {
                    break;
                }
                first=first->down;
            }*/

           // if(flag==0)
            //{
                struct krushkal *ptr=new(krushkal);
                ptr->first=start->value;
                ptr->second=(curr->temp)->value;
                ptr->weight=curr->weight;
                ptr->next=NULL;

               if(*mini==NULL)
               {
                *mini=ptr;
               }

               else
               {
                   struct krushkal *minwa=*mini;
                   while(minwa->next!=NULL)
                   {
                       minwa=minwa->next;
                   }
                   minwa->next=ptr;
               }
            //}

            curr=curr->next;
      }

           start=start->down;
 }

}



void display(struct vertex *start)
{

    while(start!=NULL)
    {
        cout<<start->value<<"  ";
        struct edge *curr=start->head;
        while(curr!=NULL)
        {
            cout<<(curr->temp)->value<<"  ";
            curr=curr->next;
        }
        cout<<endl;
        start=start->down;
    }


}