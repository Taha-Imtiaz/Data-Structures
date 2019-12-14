#include <iostream>
using namespace std;

class list{
public:

list()
{
    this->value= 0;
    this->next= NULL;
}

int getvalue()
{
    return this->value;
}



void push(list **top,char element)
{
    list *ptr= NULL;
    if(*top==NULL)
    {
       ptr= (list*)malloc(sizeof(list));
      // cout<<"\nThe pushed element is "<<element<<".\n";
       ptr->value= element;
       ptr->next= NULL;
       *top= ptr;
    }
    else
    {
        list *temp;
        temp= *top;
        ptr= (list*)malloc(sizeof(list));
        //cout<<"\nThe pushed element is "<<element<<".\n";
        ptr->value= element;
        *top= ptr;
        ptr->next= temp;
         
    }
}

bool IsEmpty(list *top)
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


char pop(list **top)
{
    if(*top==NULL)
    {
        cout<<"\nError! Stack is empty.\n\n";
        return '0';
    }
    list *curr= *top;  
    char result;

   if(curr->next!=NULL)
   {
       list *temp= NULL;
       temp= (*top)->next;
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       result= curr->value;
       *top= temp; 
       free(curr);
           
   }
   else
   {
       //cout<<"\nThe poped element is "<<curr->value<<".\n\n";
       result= curr->value;
       free(curr);
       *top= NULL;   
       
   }    
   return result;

}


int Precedence(char Operator)
{
    if(Operator == ')' )
    {
      return -1;
    }

    if(Operator == '(')
    {
        return 6;
    }

    if(Operator == '*' || Operator == '/')
    {
        return 5;
    }

    if(Operator == '+' || Operator == '-')
    {
        return 4;
    }

    if(Operator == '<' || Operator == '>' || Operator == '!' || Operator == '=')
    {
        return 3;
    }

    if(Operator == '&')
    {
        return 2;
    }

    if(Operator == '|')
    {
        return 1;
    }
}


void peak_stack(list *start)
{
    cout<<"\nThe elements in the stack are ";
    list *curr= start;
    while(curr!=NULL)
    {
        cout<<curr->value<<" ";
        curr= curr->next;
    }
    cout<<"\n\n";
}

char Peak(list *top)
{
    if(top)
    return top->value;
}



private:
char value;
list *next;

};