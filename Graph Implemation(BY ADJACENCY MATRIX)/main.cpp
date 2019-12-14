#include <iostream>
using namespace std;

void display_Matrix(int **,int);
void Make_Matrix(int **graph,int vertices);
void Degree(int **graph,int vertices);
void in_Degree(int **Graph,int vertices);
void out_Degree(int **Graph,int vertices);
void Make_Directed_Matrix(int **Graph,int vertex);
bool is_Connected(int **);
void DeleteEdge(int **Graph);
void Delete_Edge(int **graph);
int main()
{
   int vertices,vertex;
   cout<<endl;
   cout<<"===============================================UNDIRECTED GRAPH=========================================================";
   cout<<"\nEnter the number of Vertices for the undirected graph"<<endl;
   cin>>vertices;
   // cout<<"Enter "<<vertices<<" vertices";
   int **graph=new int *[vertices];
   for(int i=0;i<vertices;i++)
   {
       graph[i]=NULL;
   }

    Make_Matrix(graph,vertices);
    cout<<"===============================================ADJACANCY MATRIX=========================================================";
    display_Matrix(graph,vertices);
    cout<<"====================================================DEGREE==============================================================";
    Degree(graph,vertices);
    cout<<"========================================================IS CONNECTED====================================================";
    is_Connected(graph);
     cout<<endl;
     Delete_Edge(graph);
     cout<<"===================================================DELETE EDGE==========================================================";
     display_Matrix(graph,vertices);
   cout<<"===============================================DIRECTED GRAPH=========================================================";
   cout<<"\nEnter the number of Vertices for the directed graph"<<endl;
   cin>>vertex;
   // cout<<"Enter "<<vertices<<" vertices";
   int **Graph=new int *[vertex];
   for(int i=0;i<vertex;i++)
   {
       Graph[i]=NULL;
   }
     Make_Directed_Matrix(Graph,vertex);
    cout<<"===============================================ADJACANCY MATRIX=========================================================";
    display_Matrix(Graph,vertex);
    cout<<"=================================================IN DEGREE==============================================================";
    in_Degree(Graph,vertex);
      cout<<"=================================================OUT DEGREE=============================================================";
    out_Degree(Graph,vertex);
    cout<<"========================================================IS CONNECTED====================================================";
    is_Connected(Graph);
     DeleteEdge(Graph);
     cout<<"===================================================DELETE EDGE==========================================================";
     display_Matrix(Graph,vertex);
   }

   void Degree(int **graph,int vertices)
   {
       int count=0;
       char temp='A';
        for(int i=0;i<vertices;i++)
        {
        for(int j=0;j<vertices;j++)
        {
            if(graph[j][i]==1)
            {
              count++;

            }

        }
        cout<<"\nDegree of "<<temp <<" is:\t"<<count;
        temp++;
        count=0;

        }
        cout<<"\n\n";
   }

   void in_Degree(int **Graph,int vertices)
   {
        int count=0;
       char temp='A';
       cout<<"\n\n";
        for(int i=0;i<vertices;i++)
        {
        for(int j=0;j<vertices;j++)
        {
            if(Graph[j][i]==1)
            {
              count++;

            }

        }
        cout<<"\nIn Degree of "<<temp <<" is:\t"<<count;
        temp++;
        count=0;
        }
         cout<<"\n\n";
   }

   void out_Degree(int **Graph,int vertices)
   {
        int count=0;
       char temp='A';
       cout<<"\n\n";
        for(int i=0;i<vertices;i++)
        {
        for(int j=0;j<vertices;j++)
        {
            if(Graph[i][j]==1)
            {
              count++;

            }

        }
        cout<<"\nOut Degree of "<<temp <<" is:\t"<<count;
        temp++;
        count=0;
        }
         cout<<"\n\n";
   }

  void Make_Directed_Matrix(int **Graph,int vertex)

   {
       int edges;
       int v1,v2;

       for(int i=0;i<vertex;i++)
       {
           Graph[i]=new int[vertex];
           //graph[i]=NULL;
           for(int j=0;j<vertex;j++)

           {

               Graph[i][j]=0;
           }
       }
       cout<<"Enter the number of edges of directed graph"<<endl;
       cin>>edges;
       for(int i=0;i<edges;i++)
       {
        cout<<"Enter the vertex pair for edge:\t"<<i+1<<endl;
        cout<<"Vertex 1:\t\n";
        cin>>v1;
        cout<<"Vertex 2:\t\n";
        cin>>v2;
        //for undirected graph AB and BA both are not 1
        Graph[v1-1][v2-1]=1;
         //graph[v2-1][v1-1]=1;
       }
   }

   void DeleteEdge(int **Graph)
{
    //struct Graph *ptr=*G1;
    int col,row;
    cout<<"Enter Vertex No which you want to Delete:"<<endl;
    cout<<"Row: ";
    cin>>row;
    cout<<"Column: ";
    cin>>col;
    Graph[row-1][col-1]=0;
}
  void Make_Matrix(int **graph,int vertices)
   {
       int edges;
       int v1,v2;

       for(int i=0;i<vertices;i++)
       {
           graph[i]=new int[vertices];
           //graph[i]=NULL;
           for(int j=0;j<vertices;j++)

           {

               graph[i][j]=0;
           }
       }
       cout<<"Enter the number of edges of Undirected graph"<<endl;
       cin>>edges;
       for(int i=0;i<edges;i++)
       {
        cout<<"Enter the vertex pair for edge:\t"<<i+1<<endl;
        cout<<"Vertex 1:\t\n";
        cin>>v1;
        cout<<"Vertex 2:\t\n";
        cin>>v2;
        //for undirected graph AB and BA both are 1
        graph[v1-1][v2-1]=1;
         graph[v2-1][v1-1]=1;
       }
   }

  void Delete_Edge(int **graph)
{
    //struct Graph *ptr=*G1;
    int col,row;
    cout<<"Enter Vertex No which you want to Delete:"<<endl;
    cout<<"Row: ";
    cin>>row;
    cout<<"Column: ";
    cin>>col;
    graph[row-1][col-1]=0;
    graph[col-1][row-1]=0;
}
void display_Matrix(int **graph,int vertices)
{
    cout<<"\n\n";
    char Count='A';
    char temp='A';
 for(int i=0;i<vertices;i++)
 {
     cout<<"\t"<<temp;
     temp++;
 }
 cout<<"\n\n";

    for(int i=0;i<vertices;i++)
    {
        cout<<Count;
        for(int j=0;j<vertices;j++)
        {

                cout<<"\t"<<graph[i][j];

        }
        cout<<"\n";
        Count++;
    }
}
bool is_Connected(int **graph)
{
    int source,destination;
    cout<<"Enter source vertex:\t";
    cin>>source;
    cout<<"Enter Destination Vertex";
    cin>>destination;
    if(graph[source-1][destination-1]==1)
    {
        cout<<source<<" and "<<destination<<" are connected\n";
        return true;
    }
    else
    {
        cout<<source<<" and "<<destination<<" are not connected\n";
        return false;
    }
    cout<<endl;
}
