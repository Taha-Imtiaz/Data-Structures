#include <iostream>
#include<string>
#include "linkedlist.h"
#include "ExppressionTree.h"
using namespace std;

int main()
{
list *start=0;
string infix = "a*(b+c)-d";
string preFix = start->To_Prefix(infix);
cout<<"\nThe Prefix Expression is:"<<preFix<<endl<<endl;
//cout<<preFix;
Tree *root = NULL;
root->ConstructExpTree(&root,preFix);
root->Inorder_Traversal(root);
cout<<"\n\n";
system("pause");
}