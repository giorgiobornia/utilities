/* ------------------------------------ *
 * Nested for                           *
 * ------------------------------------ */

#include <stdio.h>


int main ()
{
  int i, j, k, pippo;

  for (i = 1; i <= 2; i++) {
      
    printf ("i: %d\n",i);
    
    for (j = 1; j <= 2; j++) {
      printf ("     j: %d\n",j);
    }
    
    printf ("     end of j cycle\n");
  }
  
  printf ("end of i cycle\n\n");

  for (i=1; i<=10; i++) 
    for (j=1; j<=10; j++) 
      for (k=1; k<=10; k++)
         pippo = i+j+k;

  printf("pippo: %d\n",pippo);

  return 0;  
}

