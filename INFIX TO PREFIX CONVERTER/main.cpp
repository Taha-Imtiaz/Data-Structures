#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<iostream>
#include<string>
//void Innfix(string);
using namespace std;
struct node
{
string value;
struct node *next;
};
/*void Innfix(string input)
{
    for(int i=0;i<input.length();i++)
    {
                cout<<input[i]<<endl;
    }

}*/

struct Stack
{
   char value;
    struct Stack *next;
};
void push_value(struct Stack **top,char element)
{

    struct Stack *ptr;

    ptr=(struct Stack*)malloc(sizeof(struct Stack));
    ptr->value=element;
//    printf("Pushed value is %d\n",element);
    ptr->next=*top;
      *top=ptr;


}
char pop_value(struct Stack **top)
{
    if(*top==NULL)
    {
        printf("\nStack is underflow");
    }
   if(*top!=NULL)
    {


     struct Stack *temp;
    temp=*top;
    (*top)=(*top)->next;
    //printf("%d has popped\n",temp->value);
    free(temp);
    return temp->value;
}
}

void peek_stack(struct Stack *start)
{
    struct Stack *curr=start;
    printf("The Elements in a stack are\n");
    while(curr!=NULL)
    {
        printf("%d\n",curr->value);
        curr=curr->next;
    }
}
char Peak(struct Stack *top)
{
    if(top!=NULL)
        return top->value;
}


int Check_Precedence(char Operator)
{
 if (Operator=='(')
 {
     return 6;
 }
 else if(Operator=='*'||Operator=='/'||Operator=='%')
 {
     return 5;
 }
 else if(Operator=='+'||Operator=='-')
 {
     return 4;
 }
 else if(Operator=='<'||Operator=='>'||Operator=='='||Operator=='~')
 {
     return 3;
 }
 else if(Operator=='&')
 {
     return 2;
 }
 else if(Operator=='|')
 {
     return 1;
 }
 else if(Operator==')')
 {
     return -1;
 }

}

bool IsEmpty(struct Stack *top)
{
    if(top==NULL)
        return true;
    else
        return false;
}
void insert(struct node **Infix)

{

    struct node *ptr;
    string input;
   ptr=(struct node*)malloc(sizeof(struct node));
   cout<<"\nEnter Infix Expression\t";
   cin>>input;
    ptr->value=input;
    ptr->next=NULL;
    if(*Infix==NULL)
    {
        *Infix=ptr;

    }
    else
    {
    struct node * curr=*Infix;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
         curr->next=ptr;
    }

//Innfix(input);

}
void Infix_Prefix(struct node *Infix)
{
    struct node *curr=Infix;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    string infix=curr->value;
   // cout<<endl<<infix;

   string postFix = "";
int n = infix.length();
string reverseInfix="";
string preFix;
char peak;
int precPeak,precPresent;
//list stack;
struct Stack *top = NULL;

for(int i=n-1;i>=0;i--)
{
    reverseInfix.push_back(infix[i]);
}
//cout<<"\nReverse string is:\t"<<reverseInfix;
 //cout<<"\nReverse:";
for(int i=0;i<=n-1;i++)
{
   // cout<<reverseInfix[i];
   if(reverseInfix[i]=='(')
   {
       reverseInfix[i]=')';
   }
   else if(reverseInfix[i]==')')
   {
    reverseInfix[i]='(';
   }
}
cout<<"\n";
/*for(int i=0;i<=n;i++)
{
 cout<<reverseInfix[i];
}*/
for(int i=0;i<=n;i++)
{
 if((reverseInfix[i] >= 'A' && reverseInfix[i]<= 'Z') || (reverseInfix[i] >= 'a' && reverseInfix[i] <= 'z')|| (reverseInfix[i] >= '0' &&reverseInfix[i] <= '9'))
  {
  postFix.push_back(reverseInfix[i]);
  }
  else
  {
    if(!(IsEmpty(top)))
    {
        peak= Peak(top);
        precPeak = Check_Precedence(peak);
        precPresent =Check_Precedence(reverseInfix[i]);
    }
     if(IsEmpty(top) || peak == '(' ||  precPresent > precPeak)
    {
      push_value(&top,reverseInfix[i]);
    }

   else if(reverseInfix[i] == ')')
    {
      while(peak!= '(')
      {
        postFix.push_back(pop_value(&top));
        peak = Peak(top);
      }
      pop_value(&top);
    }

    else if(precPresent <= precPeak && peak!= '(')
    {
      while(precPeak >= precPresent && !(IsEmpty(top)))
      {
           postFix.push_back(pop_value(&top));
           precPeak = Check_Precedence(Peak(top));
      }
      push_value(&top,reverseInfix[i]);
    }
else if(!top){
while(!(IsEmpty(top)))
{
  postFix.push_back(pop_value(&top));
}
  }
  }
}




//cout<<"\nPostfix is:\t"<<postFix<<endl;
//cout<<"\nPrefix is:\t";
for(int i=n-1;i>=0;i--)
{
  preFix.push_back(postFix[i]);
}
//cout<<"\nThe Prefix of the given infix expression is:\t";
/*for(int i=n-1;i>=0;i--)
{
    cout<<preFix[i];
}*/
//cout<<"\nPrefix is:\t"<<preFix<<endl;
cout<<"\nThe Prefix of the given infix expression is:\t"<<preFix;
}

void display_Infix(struct node *Infix)

{
  struct node * curr=Infix;
    while(curr->next!=NULL)
    {

       // cout<<endl<<"Infix is:  "<<curr->value;
         curr=curr->next;

    }
 cout<<endl<<"Infix is:  "<<curr->value;
}



//void Infix_Postfix
int main()
{
struct node* Infix=NULL;
insert(&Infix);
display_Infix(Infix);
Infix_Prefix(Infix);
cout<<endl<<endl;
insert(&Infix);
display_Infix(Infix);
Infix_Prefix(Infix);
}