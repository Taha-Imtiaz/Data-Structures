#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_Of_Elements,i,j,hold;
    printf("Enter the number of elements in the array");
    scanf("%d",&no_Of_Elements);
    int array[no_Of_Elements];
    printf("\nEnter Elements");
       for(i=0;i<no_Of_Elements;i++)
      {
          scanf("%d",&array[i]);
      }
    for(i=1;i<=no_Of_Elements-1;i++)
    {
        hold= array[i];
        j=i;
      while(hold<array[j-1])
        {
            if(j<=0)
            break;
            array[j]=array[j-1];
            j--;
    }
    array[j]=hold;
    }
 printf("\nElements are:");
      for(i=0;i<no_Of_Elements;i++)
      {
          printf("\n%d\n",array[i]);
      }
}

