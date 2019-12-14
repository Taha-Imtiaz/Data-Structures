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
       //cout<<"\nThe pushed element is "<<element<<".\n";
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


string To_Prefix(string infix)
{
    string rev_infix = Reverse_Exp(infix);
    string Postfix = To_Postfix(rev_infix);
    string Prefix = Reverse_Exp(Postfix);
    return Prefix;
}

string Reverse_Exp(string Expression)
{
  string reverse = "";
  for(int i= (Expression.length())-1; i>=0;i--)
  {
      if(Expression[i] == '(')
      {
          reverse.push_back(')');
      }
      else
      {
        if(Expression[i] == ')')
        {
          reverse.push_back('(');
        }
        else
        {
            reverse.push_back(Expression[i]);
        }      
      }
  }
  return reverse;    
}


string To_Postfix(string infix)
{
  string postFix = "";
  int n = infix.length();
  char peak=0;
  int precPeak=0,precPresent=0;
  list stack;
  list *top = NULL;

for(int i=0;i<n;i++)
{
 if(Is_Operand(infix[i]))
  {
  postFix.push_back(infix[i]);
  }
  else
  {
    if(!(stack.IsEmpty(top)))
    {
        peak= stack.Peak(top);
        precPeak = stack.Precedence(peak);
        precPresent = stack.Precedence(infix[i]);
    }
    if(stack.IsEmpty(top) || peak == '(' ||  precPresent > precPeak)
    {
      stack.push(&top,infix[i]);
    }

    if(infix[i] == ')')
    {
      while(peak!= '(')
      {
        postFix.push_back(stack.pop(&top));
        peak = stack.Peak(top);
      }
      stack.pop(&top);
    }

    if(precPresent <= precPeak && peak!= '(')
    {
      while(precPeak >= precPresent && !(stack.IsEmpty(top)))
      {
           postFix.push_back(stack.pop(&top));
           precPeak = stack.Precedence(stack.Peak(top));
      }
      stack.push(&top,infix[i]);
    }
    
  }
}

while(!(stack.IsEmpty(top)))
{
  postFix.push_back(stack.pop(&top));
}

 return postFix;
}


bool Is_Operator(char ch)
{
    int flag = 0;
    string operators= "+-*/!=()><&|";
    for(int i=0;i<operators.length();i++)
    {
        if(operators[i] == ch)
        {
            flag++;
            break;
        }
    }
    if(flag > 0)
    {
        return true;
    }
    else
    {
        return false;
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

bool Is_Operand(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))
    {
        return true;
    }
    else
    {
        return false;
    }
}

private:
char value;
list *next;

};