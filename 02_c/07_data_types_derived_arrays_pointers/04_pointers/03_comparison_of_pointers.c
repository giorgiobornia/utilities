#include <stdio.h>


int main() {
    
  int *p, *q;
  int m, n;
  
  printf("*p = ");
  scanf("%d", &m);
  p = &m;
  
  printf("*q = ");
  scanf("%d", &n);
  q = &n;
  
  printf("\n*p = %d   p = %lX  &p = %lX,\n  *q = %d    q = %lX   &q = %lX\n\n", *p, p, &p, *q, q, &q);
  
  if(p != q) {
      
	 if (*p == *q) *p = *q + 1;
	 else           q = p;
     
	 printf("*p = %d   p = %lX  &p = %lX,\n  *q = %d    q = %lX   &q = %lX\n\n", *p, p, &p, *q, q, &q);
     
  }

  return 0;  
    
}
