#include <stdio.h>  
  
int main() {
  
 printf("fare il watch delle espressioni &n, n, &p, p, *p\n");
    
  int n;
  int *p;
  n = 100;
  p = &n;
  n = 200;
  (*p)++;
  p++;
  p = &n;
  
  return 0;
  
}

  
  
  
  
