#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_Of_Elements,i,j,temp;
    printf("Enter the number of elements in the array");
    scanf("%d",&no_Of_Elements);
    int array[no_Of_Elements];
    printf("\nEnter Elements");
       for(i=0;i<no_Of_Elements;i++)
      {
          scanf("%d",&array[i]);
      }
    for(i=0;i<no_Of_Elements-1;i++)
    {
        for(j=0;j<no_Of_Elements-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
 printf("\nElements are:");
      for(i=0;i<no_Of_Elements;i++)
      {
          printf("\n%d\n",array[i]);
      }
}
