#include <stdio.h>  



int main() {
    
    struct point {
     
        int a1;
        int a2;
        char a3;
        
    } hello; /* I declared a struct */

    
    hello.a1 = 79;
    
    (&hello)->a1 = 79; /* See later: The dot operator is equivalent to first referencing and then using the arrow operator */

  
  return 0;
  
} 
