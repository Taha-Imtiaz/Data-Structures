#ifndef ExpressionTree_h
#define ExpressionTree_h


#include <iostream>
#include <stack>
#include "linkedlistTree.h"
//#include "operand.h"
using namespace std;




class Tree{
public:

Tree()
{
  this->value=' ';
  this->left= NULL;
  this->right= NULL;
}

void ConstructExpTree(Tree **root,string prefix)
{
  listTree stack;
  listTree *top = NULL;
  Tree *ptr1, *ptr2;
    for(int i=(prefix.length())-1;i>=0;i--)
    {
      if(!(isOperator(prefix[i])))
      {
       Tree *operand = (Tree*)malloc(sizeof(Tree));
        operand->value= prefix[i];
        operand->right = NULL;
        operand->left = NULL;
        stack.push(&top,operand); 
      }
      else
      {
        Tree *Operator = (Tree*)malloc(sizeof(Tree));
        Operator->value= prefix[i];
        ptr1= stack.pop(&top);
        ptr2= stack.pop(&top);
        Operator->left = ptr1;
        Operator->right = ptr2;
        *root= Operator;
        stack.push(&top,Operator);
      }
    }
}


/*int Evaluate_Tree(string postfix)
{
    stack <Operand> Eval_stack;
    stack <Operand> Copy_stack;
    Operand ptr1, ptr2;
    for(int i=0;i<postfix.length();i++)
    {
      if(!(isOperator(postfix[i])))
      {
        Operand Op;
        int temp;
        if(!(isEvaluated(postfix[i],postfix,i)))
        {
          if((postfix[i]>= 48) && (postfix[i] <= 57))
          {
             temp = postfix[i]-48;
          }
          else
          {
        cout<<"\nEnter the value of "<<postfix[i]<<": ";
        cin>>temp;
          }
        }
        else
        {
          if((postfix[i]>= 48) && (postfix[i] <= 57))
          {
             temp = postfix[i]-'0';
          }
          else
          {
        temp = SearchByCh(Copy_stack,postfix[i]);
          }
          }
        Op.set_val(temp);
        Op.set_ch(postfix[i]);
        Eval_stack.push(Op); 
        Copy_stack.push(Op);
      }
      else
      {
        Operand Operator;
        Operator.set_ch(postfix[i]);
        ptr2= Eval_stack.top();
        Eval_stack.pop();
        ptr1= Eval_stack.top();
        Eval_stack.top();
        Operator.set_val(Eval_val(Operator.get_ch(),ptr1.get_val(),ptr2.get_val()));
        Operator.set_ch(' ');
        Eval_stack.emplace(Operator);
      }
    }
    
    cout<<Eval_stack.top();
    while(!(Eval_stack.empty()))
    {
    Eval_stack.pop();     
    }
}*/


int Eval_val(char ch,int val1,int val2)
{
 if(ch == '*')
 return val1*val2;

 if(ch == '/')
 return val1/val2;

 if(ch == '+')
 return val1+val2;

 if(ch == '-')
 return val1-val2;

 if(ch == '!')
 {
   if(val1 != val2)
   {
     return true;
   }
   else
   {
     return false;
   }
 }

 if(ch == '=')
 {
   if(val1 == val2)
   {
     return true;
   }
   else
   {
     return false;
   }
 }

 if(ch == '>')
 {
   if(val1 > val2)
   {
     return true;
   }
   else
   {
     return false;
   }
 }

 if(ch == '<')
 {
   if(val1 < val2)
   {
     return true;
   }
   else
   {
     return false;
   }
 }

}


/*int SearchByCh(stack <Operand> Orgstack,char ch)
{
  int flag = 0;
  Operand Op;
  while(!(Orgstack.empty()))
  {
    Op = Orgstack.top();
    if(Op.get_ch()== ch)
    {
          flag++;
          break;
    }
    else
    {
      Orgstack.pop();
    }
  }
  if(flag > 0)
  {
    return Op.get_val();
  }
}*/


bool isEvaluated(char ch,string prefix,int n)
{
     int flag=0;
     for(int i=0;i<n;i++)
     {
       if(ch == prefix[i])
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


bool isOperator(char ch)
{
 string operators= "*/+-&|!=><";
 int flag=0;
 for(int i=0;i<operators.length();i++)
 {
   if(operators[i] == ch)
   {
     flag++;
     break;
   }
 }
 if(flag>0)
 {
   return true;
 }
 else
 {
   return false;
 }

}


void Inorder_Traversal(Tree *root)
{
  if(root->left)
  {
    Inorder_Traversal(root->left);
  }
  cout<<root->value<<" ";
  if(root->right)
  {
    Inorder_Traversal(root->right);
  }
}


void Preorder_Traversal(Tree *root)
{
  cout<<root->value<<" ";
  if(root->left)
  {
    Preorder_Traversal(root->left);
  }
  if(root->right)
  {
    Preorder_Traversal(root->right);
  }
}


void Postorder_Traversal(Tree *root)
{
  if(root->left)
  {
    Postorder_Traversal(root->left);
  }
  if(root->right)
  {
    Postorder_Traversal(root->right);
  }
  cout<<root->value<<" ";
}


private:
char value;
Tree *right;
Tree *left;

};
#endif