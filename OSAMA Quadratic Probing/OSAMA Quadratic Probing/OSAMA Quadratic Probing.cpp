#include <iostream>
#include <cmath>
using namespace std;

void print(int *arr,int n)
{
	cout<<"\nThe elements of the array are: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n";
}



int Linear_Probing(int *arr,int index,int size)
{
	int temp= index;
	int flag=-1;
	temp++;
	while(temp!=index)
	{
		if(arr[temp]==-1)
		{
			flag++;
			break;
		}
		else{
			temp= (temp+1)%size;
		}
	}
	if(flag>-1)
	{
		return temp;
	}
	else
	{
		return flag;
	}
	
}



int Quadratic_Probing(int *arr,int index,int size)
{	
	
	int temp= index, i=1;
	int flag=-1;
	temp++;
	while(i<100)
	{
		if(arr[temp]==-1)
		{
			flag++;
			break;
		}
		else{
			int result=i*i;
			temp= (index+result)%size;
			i++;
		}
	}
	if(flag>-1)
	{
		return temp;
	}
	else
	{
		return flag;
	}
}




int Quadratic_Probing_Search(int *arr,int index,int size,int search)
{	
	
	int temp= index, i=1;
	int flag=-1;
	temp++;
	while(i<100)
	{
		if(arr[temp]==search)
		{
			flag++;
			break;
		}
		else{
			int result= i*i;
			temp= (temp+result)%size;
			i++;
		}
	}
	if(flag>-1)
	{
		return temp;
	}
	else
	{
		return flag;
	}
}


int Linear_Probing_search(int *arr,int index,int size,int search)
{
	int temp= index;
	int flag=-1;
	temp++;
	while(temp!=index)
	{
		if(arr[temp]==search)
		{
			flag++;
			break;
		}
		else{
			temp= (temp+1)%size;
		}
	}
	if(flag>-1)
	{
		return temp;
	}
	else
	{
		return flag;
	}
	
}


int Hashing (int *arr,int size,int value)
{
	int index= value%size;
    if(arr[index]==-1)
    {
       return index;	
	}
	else
	{
		int rep_index= Quadratic_Probing(arr,index,size);
		return rep_index;
	}
	
}


void insert_element(int *arr,int value,int n)
{
 int index = Hashing(arr,n,value);
 if(index!=-1)
 {
 	arr[index]=value;
 }
 else
 {
 	cout<<"\nThe array is full.\n";
 }
}



void search_element(int *arr,int size,int search)
{
	int index= search%size;
	if(arr[index]==search)
	{
	    cout<<"\nThe element is present at index "<<index<<" .\n";	
	}
	else
	{
	  int rep_index =	Quadratic_Probing_Search( arr,index,size,search);
	  if(rep_index==-1)
	  {
	  	cout<<"\n\nThe element is not present in array.\n\n";
	  }
	  else
	  {
	  	cout<<"\nThe element is present at index "<<rep_index<<" .\n";
	  }
	
	}
}




int main() 
{	
	int *arr,n,search;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	arr= new int[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=-1;
	}
	
	for(int j=0;j<10;j++)
	{
		int val;
		cout<<"\nEnter value of element to enter: ";
		cin>>val;
		insert_element(arr,val,n);
	}
	print(arr,n);
	cout<<"\n\nEnter the element that you want to search: ";
	cin>>search;
	search_element(arr,n,search);
	search_element(arr,n,47);
	search_element(arr,n,0);
	system("pause");
}