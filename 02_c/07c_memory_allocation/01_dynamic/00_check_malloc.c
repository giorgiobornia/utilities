#include <stdio.h>
#include <stdlib.h>



int main() {
    
int *p;
p = (int *) malloc( 100000000000 * sizeof(int) );

  /* If it doesn't work it returns a zero */

 if( !p ) {
  printf("Impossible to allocate in the heap\n");
  return 1;
} else {

    free(p);
}

   
 return 0;
  
}
