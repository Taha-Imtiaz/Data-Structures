#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
void Hashing_insert(int arr[],int size);
int Quadratic_Probbing(int arr[],int size,int input,int index,string WhatToDo);
int Hashing_Search(int arr[],int size);
void display(int *arr,int size);

int main()
{
	int arr[10]={NULL};
	int n=sizeof(arr)/sizeof(arr[0]);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
    Hashing_insert(arr,n);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
	Hashing_insert(arr,n);
    Hashing_insert(arr,n);


	display(arr,n);
		Hashing_Search(arr,n);
}
void display(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==NULL)
		{
			cout<<endl<<i<<"="<<"NULL";
		}
		else
		{
			cout<<endl<<i<<"="<<arr[i];
		}
	}
}
int Quadratic_Probbing(int arr[],int size,int input,int index,string WhatToDo)
{

	if(WhatToDo=="insert")
	{
	    int act=index,flag=0,j=0,remain;
        do
		{
			j++;

			act=(index+(j*j))%size;
			/*if(act>=size)
			{
			remain=index/size;
			index=index-(remain*size);
			}*/

			/*if(index==act)
			{
				count++;
			}*/
			/*if(count==10)
			{
			break;
			}*/
      //  index=index%size;
		}
		while(arr[act]!=NULL);
		return act;
	}
	else if(WhatToDo=="search")
	{
	    int act=index,flag=0,j=0,remain;
		do
		{

			j++;
			index=(index+(j*j))%size;
			/*if(index>=size)
			{
			    remain=index/size;
			index=index-(remain*size);
			}*/
		//	if(index==act)
			//{
				//counter++;
			//}
			//if(counter==10)
		//	{
			//break;
			//}
		}
		while(input!=arr[index]);

		return index;
	}
}

void Hashing_insert(int arr[],int size)
{
	int input,index;
	cout<<"Enter Input=";
	cin>>input;
	index=input%size;
	if(arr[index]!=NULL)
	{
		index=Quadratic_Probbing(arr,size,input,index,"insert");
	}
	arr[index]=input;
}
int Hashing_Search(int arr[],int size)
{
	int input,index;
	cout<<"\n\nSearch Number=";
	cin>>input;
	index=input%size;
	if(arr[index]==NULL)
	{
		cout<<"Sorry Number do not exist"<<endl;
	}
	else
	{
		if(arr[index]!=NULL)
		{
		index=Quadratic_Probbing(arr,size,input,index,"search");

		}
	}
	cout<<"Found at index="<<index;
}
