#include <stdio.h>
#include <stdlib.h>


//  void try_to_overwrite_pointer_without_success(int * /*const*/ a) {
 void try_to_overwrite_pointer_without_success(int * a ) { /* with the notation int a[] you cannot put const for the pointer */
  
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
    
    int a[7]; /* it is not the same as with pointers! */
    
    printf("Pointer before: %d\n", a);
      
    try_to_overwrite_pointer_without_success(a);
    
    printf("Pointer after:  %d\n", a); /* The pointer is not overwritten */

    
    //can I pass the address of a STATIC array in such a way that it can be MODIFIED? 
    // If it was a POINTER, I could do it by passing the POINTER of the POINTER
    // With a static array, it seems like I cannot
    
    // Why would I want to pass and modify the address of a STATIC array?
    
    try_to_overwrite_pointer_with_success(&a); /* &a is not of (int **) type, it is of type int (*)[7]  ! */
//     
    printf("Pointer after:  %d\n", a);

  
  return 0;
    
}    
