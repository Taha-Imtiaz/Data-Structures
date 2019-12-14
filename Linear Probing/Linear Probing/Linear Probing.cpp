#include<iostream>
#include<string>
using namespace std;
void Hashing_insert(int arr[],int size);
int Linear_Probbing(int arr[],int size,int input,int index,string WhatToDo);
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

	Hashing_Search(arr,n);

	display(arr,n);
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
int Linear_Probbing(int arr[],int size,int input,int index,string WhatToDo)
{
	int act=index,flag=0;
	if(WhatToDo=="insert")
	{
		do
		{
			index++;
			if(index==size)
			{
				index=0;
			}
			if(index==act)
			{
				break;
			}
		}
		while(arr[index]!=NULL);
		return index;
	}
	else if(WhatToDo=="search")
	{
		do
		{
			index++;
			if(index==size)
			{
				index=0;
				flag++;
			}
			if(index==act)
			{
				cout<<"Number NOT FOUND";
				flag=0;
				break;
			}
		}
		while(input!=arr[index]);
		if(flag>0)
		{
			cout<<"Found at index="<<index;
		}
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
		index=Linear_Probbing(arr,size,input,index,"insert");
	}
	arr[index]=input;
}
int Hashing_Search(int arr[],int size)
{
	int input,index;
	cout<<"Search Number=";
	cin>>input;
	index=input%size;
	if(arr[index]==NULL)
	{
		cout<<"Sorry Number do not exist"<<endl;
	}
	else
	{
		if(arr[index]!=input)
		{
		index=Linear_Probbing(arr,size,input,index,"search");

		}
	}
	cout<<"Found at index="<<index;
}
