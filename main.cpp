#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void Print_Vertex(struct Vertex *start);

struct Vertex
{
    char value;
    struct Vertex *next;
    struct Edge *header;
};
struct Edge
{
    char value;
    struct Edge *next;
};
void  Add_Vertex(struct Vertex **mystart)
{
     char name;
    struct Vertex *ptr=NULL;
   cout<<"Enter the Vertex\n";
   // fflush(stdin);
   cin>>name;
    ptr=(struct Vertex*)malloc(sizeof(struct Vertex));
    ptr->value=name;
    ptr->next=NULL;
    ptr->header=NULL;
    if(*mystart==NULL){


    *mystart=ptr;
}
else
{

    struct Vertex *curr=*mystart;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=ptr;
}
}
void Add_Edge(struct Edge **header)
{
    char name;
//int seat_no;
cout<<"Enter vertex you want to join:";
//fflush(stdin);
cin>>name;
struct Edge *ptr=NULL;
ptr=(struct Edge*)malloc(sizeof(struct Edge));

	ptr->value=name;
    //ptr->Seat_NO=seat_no;

    ptr->next=NULL;
if(*header==NULL)
{
    *header=ptr;
}
else
{

    struct Edge *curr=*header;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=ptr;
}
}
struct Vertex* search_vertex(struct Vertex *start,char search)
{
    struct Vertex *curr=start;
    while(curr!=NULL)
    {
        if(search==curr->value)
        {
           cout<<search<<" Vertex is found\n";
            break;

        }
        curr=curr->next;
    }
    return curr;
}

void search_edge(struct Vertex *start,char value)
{
    struct Vertex *currVertex=start;
    while (currVertex!=NULL)
    {
       struct Edge *currEdge =currVertex->header;
      while(currEdge!=NULL)
      {
          if(currEdge->value==value)
          {
              cout<<"Edge "<<currEdge->value<<" found in "<<currVertex;
              break;
          }
          currEdge=currEdge->next;
      }
      currVertex=currVertex->next;
    }
}
void delete_edges(struct Edge **header)
{
    struct Edge *curr=*header;
    while(curr!=NULL)
    {
        curr=curr->next;
        free(curr);
    }
}
void delete_vertex(struct Vertex **start,char name)
{
    struct Vertex *curr= *start;
    if((*start)->value==name)
    {
        delete_edges(&curr->header);
        *start=(*start)->next;
        free(curr);
    }
    else
    {
       struct Vertex *curr= (*start)->next;
        struct Vertex *prev= *start;
        while(curr!=NULL)
        {
            if(curr->value==name)
            {
                delete_edges(&(curr->header));
                prev->next=curr->next;
                free(curr);
                break;
            }
            curr=curr->next;
            prev=prev->next;
        }
    }
}

void delete_edge(struct Vertex **start,char edge_no)
{
struct Vertex *currVertex=*start;
struct Edge *currEdge=NULL;
while(currVertex!=NULL)
{
    currEdge=currVertex->header;
   if (currEdge->value==edge_no)
    {
        currVertex->header=currEdge->next;
        free(currEdge);
    }
    else
    {
        currEdge=(currVertex->header)->next;
        struct Edge *prev=currVertex->header;
        while(currEdge!=NULL)
        {
            if(currEdge->value==edge_no)
            {
                prev->next=currEdge->next;
                free(currEdge);
                break;
            }
            currEdge=currEdge->next;
            prev=prev->next;

        }
    }
    currVertex=currVertex->next;
}
}

void Print_Vertex(struct Vertex *start)
{
   struct Vertex *currVertex= start;
    while(currVertex!=NULL)
    {
        cout<<"\n\nThe edges connected with vertex" <<currVertex->value<<" are  : \n";
        struct Edge *currEdge= currVertex->header;
        while(currEdge!=NULL)
        {
          cout<<currEdge->value<<"->";
            currEdge= currEdge->next;
        }
        currVertex= currVertex->next;
    }
}
//struct Vertex
void Calculate_Degree(struct Vertex *start)
{
   struct Vertex *currVertex= start;
   int count=0,temp=1;
    while(currVertex!=NULL)
    {
        //cout<<"\n\nThe edges connected with vertex" <<currVertex->value<<" are  : \n";
        struct Edge *currEdge= currVertex->header;
        while(currEdge!=NULL)
        {
          //cout<<currEdge->value<<"->";
          count++;
          
          
         cout<<"In Degree of "<<currEdge->value<<" is "<<temp<<endl;
            currEdge= currEdge->next;
        }
		cout<<"Out Degree of "<<currVertex->value<<" is "<<count<<endl;
        temp++;
        currVertex= currVertex->next; 
        count=0,temp=1;
    }
}
int main()
{
    struct Vertex *start=NULL;
    int choice;
    while(1)
    {


   cout<<"Select any one from the following options\n";
   cout<<"1.ADD VERTEX\n2.ADD EDGE\n3.Delete vertex\n4.Delete edge\n5.Print vertex\n6.Calculate Degree\n7.Exit\n";
  cout<<"Enter your choice";
  cin>>choice;
   switch(choice)
   {
   case 1:
       {
        Add_Vertex(&start);
            break;
        }
    case 2:
       {

           char Name;
          cout<<"Enter the name of Vertex to search";
          cin>>Name;
          struct Vertex *curr=search_vertex(start,Name);
           if(curr==NULL)
           {
              cout<<"No search vertex found\n";
               break;
           }
           else
           {
              Add_Edge(&(curr->header));
               break;
           }


   }
    case 3:
       {


       char Name;
           cout<<"Enter the name of Vertex to delete";
           cin>>Name;
           delete_vertex(&start,Name);
            Print_Vertex(start);
           break;
       }
    case 4:
{

           char Edge_no;
           cout<<"Enter Edge no to delete";
            cin>>Edge_no;
            delete_edge(&start,Edge_no);
            Print_Vertex(start);
            break;

        }
        case 5:
        {
        Print_Vertex(start);
        break;
        }
        case 6:
        	{
       Calculate_Degree(start);
        break;
			}
        case 7:
            exit(0);
            break;
        default:
            cout<<"\nPlease select a valid choice";
}
}

}



