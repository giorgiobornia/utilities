#include <stdio.h>  



int main() {
  
  printf("With a debugger, watch the expressions &n, n, &p, p, *p\n");
    
  int n;
  int * p; /* Read from right to left: "p is a pointer to an int variable" */
  
  void * ptr_void;
  
  /* Variable initialization followed by pointer initialization */  
  n = 100;
  p = &n;

  /* Variable update */
  n = 200;
  
  /* Increase by 1 the variable pointed to by p */
  (*p)++;
  
  /* Increase the pointer by 1 unit of the type, in this case by 1 unit of int, where sizeof(int) = 4 bytes */
  p++;
  /* Increase the pointer by 1 unit of the type, in this case 1 byte */
  ptr_void ++;  
  
  
  /* Restore the value of the pointer to the address of n */
  p = &n;
  
  /* Invalid operation */
//   p + ptr_void; 
  
  
  return 0;
  
}

