#include <stdio.h>

/* which one is better? */

#define REAL_NUMBER double   /* */

typedef double real_number;  /* this is better because it declares that it is a type and not just a word to be replaced in the source code */


int main() {
    
    REAL_NUMBER  r1 = 3.14;
    
    real_number r2 = 7.9;
    
    
 return 0;
  
}


