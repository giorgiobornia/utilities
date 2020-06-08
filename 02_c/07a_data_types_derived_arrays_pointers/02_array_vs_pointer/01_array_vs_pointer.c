#include <stdio.h>

int main() {

  int * pointer_uninitialized;  /********* Pointer to int ********/
  int array_uninitialized[1];   /********* Array of int **********/

  printf("%d\n", pointer_uninitialized);
/*  printf("%d\n", *pointer_uninitialized); */  /* Segmentation fault */
  printf("%d\n",   array_uninitialized[0]);
  printf("%d\n", & array_uninitialized[0]);
  printf("%d\n", & array_uninitialized);

  
 /********* Array initialization ******/
   int array_initialized_with_length[4] = {3,7,6,9};
   int array_initialized_without_length[] = {3,7,6,9}; /* Equivalent to before, the compiler infers the size from the initializer */
//    int * pointer_initialized_without_length = {3,7,6,9};     /* Gives warnings, don't do it */

   char array_of_chars_initialized_without_length[] = "Hello, world"; 
//  char * pointer_to_chars_initialized_without_length = "Hello, world";   

   
   /* this one works: array of pointers to char */
   char * line[] = {"abc", "def", "ghi"};

   char   pc[] = "good morning";
   char * pc2  = "good morning";  /* Only works if you don't modify it after the initialization! It is like a "string literal"! */
   
   pc[2] = 'A';
//    pc2[2] = 'O'; /* Gives segmentation fault */
   
  printf("%s \n", array_of_chars_initialized_without_length);
   
   
    return 0;
    
}
