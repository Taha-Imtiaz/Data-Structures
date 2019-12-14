#include <iostream>
#include "linkedlist.h"
#include<string>
using namespace std;

int main()
{
string infix = "a*(b+c)/d";
string postFix = "";
int n = infix.length();
char peak=0;
int precPeak=0,precPresent=0;
list stack;
list *top = NULL;


for(int i=0;i<=n-1;i++)
{
 if((infix[i] >= 65 && infix[i]<= 90) || (infix[i] >= 97 && infix[i] <= 122))
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

cout<<"postFix"<<postFix<<endl;
system("pause");
}