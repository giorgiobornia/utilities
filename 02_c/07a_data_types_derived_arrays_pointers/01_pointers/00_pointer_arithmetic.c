#include <stdio.h>  
  
int main() {
  
 printf("with a debugger, watch the expressions &n, n, &p, p, *p\n");
    
  int n;
  int * p; /* Read from right to left: "p is a pointer to an int variable" */
  
  n = 100;
  
  p = &n;
  
  n = 200;
  
  (*p)++;
  
  p++;
  
  p = &n;
  
  return 0;
  
}

  
  
  
  
