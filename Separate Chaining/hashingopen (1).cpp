#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int value;
	node *next;
};

int hashfunction(int size, int value)
{
	int index;
	index = value % size;
	return index;
}

void insert(node *hashtable, int size)
{
	int index, value;
	cout << "Enter Value: ";
	cin >> value;

	index = hashfunction(size, value);

	if (hashtable[index].value == -1)
	{
		hashtable[index].value = value;
		hashtable[index].next = NULL;
		//curr = temp;
	}
	else
	{
		node *temp;  //, * curr;
		temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->next = NULL;

		node *current = &hashtable[index];

		/* cout<< "\n Check index...\n" << &index;

		for (int i=0; i<size ; i++)
		{
		cout << &current[i] <<endl;
		}*/


		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;

	}

}


void display(node *hashtable, int size)
{
	for (int i = 0; i < size; i++)
	{
		node *curr = &hashtable[i];

		if (hashtable[i].value != -1)
		{
			while (curr != NULL)
			{
				cout << curr->value << "->";
				curr = curr->next;

			}
			cout << endl << "|" << endl;
		}


	}
}

int main()
{
	int size = 10;
	node *hashtable = new node[size];

	for (int i = 0; i < size; i++)
	{
		hashtable[i].next = NULL;
		hashtable[i].value = -1;
	}

	insert(hashtable, size);
	insert(hashtable, size);
	insert(hashtable, size);
	insert(hashtable, size);
	insert(hashtable, size);
	insert(hashtable, size);

	display(hashtable, size);
	//freemem(hashtable, size);
}
