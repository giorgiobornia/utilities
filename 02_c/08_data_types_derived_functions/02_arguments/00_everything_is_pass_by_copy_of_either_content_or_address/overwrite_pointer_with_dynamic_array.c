#include <stdio.h>
#include <stdlib.h>


 void try_to_overwrite_pointer_without_success(int * /*const*/ a) { /* If you put const the pointer will not be overwritten */
  
     a = NULL;
     
      printf("Pointer inside  %d\n",  a);
      
     return;
     
 }

 void try_to_overwrite_pointer_with_success(int ** a) {
  
     * a = NULL;
     
      printf("Pointer inside  %d\n", * a);

     return;
     
 }

 
int main ()
{
    
    int * a;
    a = (int *) malloc(7 * sizeof(int)); /* To make it nonzero */
//     int a[7]; /* it is not the same as above! &a is not of (int **) type, it is of type int (*)[7]  ! */
    
    printf("Pointer before: %d\n", a);
      
    try_to_overwrite_pointer_without_success(a);
    
    printf("Pointer after:  %d\n", a); /* The pointer is not overwritten */

    try_to_overwrite_pointer_with_success(&a); /*if I pass the pointer of the pointer, I will get to access the original pointer */
    
    printf("Pointer after:  %d\n", a);

    free(a);
    
  return 0;
    
}    
