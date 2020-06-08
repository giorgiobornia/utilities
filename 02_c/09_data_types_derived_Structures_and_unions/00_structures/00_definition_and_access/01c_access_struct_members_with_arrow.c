#include <stdio.h>  



int main() {
    
    struct point {
     
        int a1;
        int a2;
        char a3;
        
    };
    
    struct point * hello;
    /* I declared a pointer to a struct... but there is no allocation yet */
//     So, if I tried to use this pointer now, I would get segmentation fault

//     First you have to ALLOCATE if you want to then be able to access
//    Again, we can avoid using malloc by first declaring a struct of the same type, but which is not a pointer   

    struct point hello_allocated;
// Then, we set the pointer to the address of the allocated struct
    hello = & hello_allocated;
   
   
    hello->a1 = 79;
    
    (*hello).a1 = 79; /* The arrow operator is equivalent to first dereferencing and then using the dot operator */

  
  return 0;
  
}
