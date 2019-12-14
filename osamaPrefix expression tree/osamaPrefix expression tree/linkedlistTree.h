#ifndef linkedlistTree_h
#define linkedlistTree_h



#include <iostream>
#include "ExppressionTree.h"
using namespace std;
class Tree;

class listTree{
public:

listTree()
{
    this->value= NULL;
    this->next= NULL;
}

Tree* getvalue()
{
    return this->value;
}



void push(listTree **top,Tree *element)
{
    listTree *ptr= NULL;
    if(*top==NULL)
    {
       ptr= (listTree*)malloc(sizeof(listTree));
       //cout<<"\nThe pushed element is "<<element<<".\n";
       ptr->value= element;
       ptr->next= NULL;
       *top= ptr;
    }
    else
    {
        listTree *temp;
        temp= *top;
        ptr= (listTree*)malloc(sizeof(listTree));
        //cout<<"\nThe pushed element is "<<element<<".\n";
        ptr->value= element;
        *top= ptr;
        ptr->next= temp;
         
    }
}





Tree* pop(listTree **top)
{
    if(*top==NULL)
    {
        cout<<"\nError! Stack is empty.\n\n";
        return NULL;
    }
    listTree *curr= *top;  
    Tree *returnVal;

   if(curr->next!=NULL)
   {
       listTree *temp= NULL;
       temp= (*top)->next;
       returnVal = curr->value;
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       *top= temp; 
       free(curr);
           
   }
   else
   {
       returnVal = curr->value;
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       free(curr);
       *top= NULL;   
       
   }    
return returnVal;
}


bool isEmpty(listTree *top)
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void peak_stack(listTree *start)
{
    cout<<"\nThe elements in the stack are ";
    listTree *curr= start;
    while(curr!=NULL)
    {
        cout<<curr->value<<" ";
        curr= curr->next;
    }
    cout<<"\n\n";
}



private:
Tree *value;
listTree *next;
};
#endif