/* ------------------------------------ *
 * Nested for                           *
 * ------------------------------------ */

#include <stdio.h>


int main ()
{
  int i, j;

  for (i = 1; i <= 10; i++) {
      
    printf ("i: %d\n",i);
    
    for (j = 1; j <= 7; j++) {
        
      printf ("     j: %d\n",j);
      
      if (j == 4) break;
      
    }
    
    printf ("end of j cycle\n");
  }
  
  printf ("end of i cycle\n");

  return 0;
}

