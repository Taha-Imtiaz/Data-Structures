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
    bool visited =false;
};
struct Edge
{
    int weight;
    struct Vertex *temp;
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
void Add_Edge(struct Edge **header,struct Vertex **edge)
{
   /* char name;
    //int seat_no;
    cout<<"Enter vertex you want to join:";
    //fflush(stdin);
    cin>>name;*/
    int weight;
    struct Edge *ptr=NULL;
    cout<<"Enter Weights for the edge";
    cin>>weight;
    ptr=(struct Edge*)malloc(sizeof(struct Edge));
    ptr->temp=(struct Vertex*)malloc(sizeof(struct Vertex));

    (ptr->temp)=(*edge);
    //ptr->Seat_NO=seat_no;
    ptr->weight=weight;
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
            if(currEdge->temp->value==value)
            {
                cout<<"Edge "<<currEdge->temp->value<<" found in "<<currVertex<<" with a weight of "<<currEdge->weight<< "units";
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
	struct Edge *del;
    while(curr!=NULL)
    {
		del=curr;
        free(del);
		curr=curr->next;

    }
}
void delete_vertex(struct Vertex **start, struct Vertex ** name)
{

	  struct Vertex *curr= *start;
	  if(curr->value==(*name)->value)
    {
        delete_edges(&curr->header);
        curr=curr->next;
        free(curr);
    }
    else
    {
       struct Vertex *curr= (*start)->next;
        struct Vertex *prev= *start;
        while(curr!=NULL)
        {
			if(curr->value==(*name)->value)
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

void delete_edge(struct Vertex *currVertex, struct Edge **header,char edge_no)
{
	struct Edge *currEdge;

    if(currVertex!=NULL)
    {
        currEdge=currVertex->header;
        if (currEdge->temp->value==edge_no)
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
                if(currEdge->temp->value==edge_no)
                {
                    prev->next=currEdge->next;
                    free(currEdge);
                    break;
                }
                currEdge=currEdge->next;
                prev=prev->next;

            }
        }
        //currVertex=currVertex->next;
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
            cout<<currEdge->temp->value<<" with a weight of "<<currEdge->weight<<" units\n";
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


            cout<<"In Degree of "<<currEdge->temp->value<<" is "<<temp<<endl;
            currEdge= currEdge->next;
        }
        cout<<"Out Degree of "<<currVertex->value<<" is "<<count<<endl;
        temp++;
        currVertex= currVertex->next;
        count=0;
        temp=1;
    }
}



struct Edge * Sort_Edge(struct Vertex *curr,struct Edge *Sort,int vertices,int edges)
{
    struct Vertex *currVertex=curr;
    int i=0,j;
    while(currVertex!=NULL)
    {
        struct Edge *currEdge=currVertex->header;

        while(currEdge!=NULL)
        {
            Sort[i]=*currEdge;
            currEdge=currEdge->next;
            i++;
        }
        curr=currVertex->next;
    }
    for(i=1;i<edges;i++)
    {
        struct Edge *Min;
        *Min=Sort[i];
        int j=i-1;
        while(j>=0&&(Sort[j].weight>Min->weight))
        {
            Sort[j+1]=Sort[j];
            j--;
        }

        Sort[j+1]=*Min;
    }
for(i=0;i<edges;i++)
    {
        cout<<Sort[i].weight;
    }
return Sort;
}

void  Kruskals(struct Vertex *start,int vertices,int edges)
{
  struct Vertex *curr=start;
  Edge *arr=new Edge[edges];
  Edge *Sort=Sort_Edge(curr,Sort,vertices,edges);
  Edge *output_array=new Edge[vertices-1];
  Edge *parent=
  for(int i=0;i<)
  int k=0;
  while(k<vertices-1)
  {
      Edge *current =Sort[k]    //Edge with the minimum weight
  }
  //whether the current
//  while(curr!=NULL)
//  {
//      struct Edge *edge =curr->header;
//      while(edge!=NULL&& edge->temp->visited==true)
//      {
//          edge=edge->next;
//      }
//      while(edge!=NULL&& edge->temp->visited!=true)
//      {
//          int i=0;
//        arr[i]=*edge;
//        arr[i].weight=(*edge).weight;
//       // arr[i]->next=(*edge)->next;
//        edge=edge->next;
//       i++;
//      }
//       curr=curr->next;
//      }
//      Kruskals(arr,edge_size);
//      //sort(arr,arr+edge_size)

  }

int main()
{
    struct Vertex *start=NULL;
    int i=0,v,e;
    int choice;
    while(1)
    {


        cout<<"Select any one from the following options\n";
        cout<<"1.ADD VERTEX\n2.ADD EDGE\n3.Delete vertex\n4.Delete edge\n5.Print vertex\n6.Calculate Degree.\n7.Sort\n8.Exit\n";
        cout<<"Enter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1:

            {
                cout<<"Enter the no.of Vertices\n";
                cin>>v;
                for(i=0;i<v;i++)
                {
                   Add_Vertex(&start);
                }

                break;
            }
            case 2:
            {

                char Name;
				char edge;
				cout<<"Enter the no. of Edges\n";
				cin>>e;
				for(i=0;i<e;i++)
                {


                cout<<"Enter the name of Vertex to search";
                cin>>Name;
                struct Vertex *curr=search_vertex(start,Name);
				cout<<"Enter second vertex";
				cin>>edge;
				struct Vertex *edges=search_vertex(start,edge);
                if(curr==NULL||edge==NULL)
                {
                    cout<<"No search vertex found\n";

                }
                else
                {
                    Add_Edge(&(curr->header),&(edges));

                }
                }
                    break;
                }
            case 3:
            {


                char Name;
                cout<<"Enter the name of Vertex to delete";
                cin>>Name;
				 struct Vertex *curr=search_vertex(start,Name);
                delete_vertex(&start,&curr);
                Print_Vertex(start);
                break;
            }
            case 4:{
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

                char Edge_no;
                cout<<"Enter Edge no to delete";
                cin>>Edge_no;
				delete_edge(curr,&(curr->header),Edge_no);
                Print_Vertex(start);
                break;
				}
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
                {
                    Kruskals(start,v,e);
                    break;
                }
            case 8:
                exit(0);
                break;
            default:
                cout<<"\nPlease select a valid choice";
        }
    }

}

