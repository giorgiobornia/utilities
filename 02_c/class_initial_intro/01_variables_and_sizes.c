#include <stdio.h>

int main()  {
    
  /* declarations of some fundamental types */

  int a; 
  float b;
  double c;
  char d;
  
  int e;
  float f;
  

  /* assignment */
  a = 13;
  b = 1.321;
  c = 44.332211;
  d = 's';
  e = 23;
  f = b;

  /* print their values */
  printf("int    a: %2d \n", a);
  printf("float  b: %e \n", b);
  printf("double c: %f \n", c);
  printf("char   d: %c \n", d);
  printf("int    e: %2d \n", e);
  printf("float  f: %e \n", f);

  /* see their dimension */
  printf("\n");
  printf("bytes per int   : %d \n", sizeof(int));
  printf("bytes per int   : %d \n", sizeof(unsigned int));
  printf("bytes per int   : %d \n", sizeof(a));
  
  printf("bytes per float : %d \n", sizeof(float));
  printf("bytes per float : %d \n", sizeof(b));
  
  printf("bytes per double: %d \n", sizeof(double));
  printf("bytes per double: %d \n", sizeof(c));
  
  printf("bytes per char  : %d \n", sizeof(char));
  printf("bytes per char  : %d \n", sizeof(d));
  
  
}
