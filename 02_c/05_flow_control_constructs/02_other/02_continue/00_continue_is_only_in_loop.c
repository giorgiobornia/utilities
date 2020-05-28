
#include <stdio.h>

int main()
{

 int i;

  for (i = 0; i < 10; i++) {
      
     printf("***** Before: %d\n", i);

     if (i == 6) continue; /* skips all the subsequent operations for that loop iteration */
     
     printf("----- After: %d\n", i);
  }

  return 0;
 
}
