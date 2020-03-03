#include <stdio.h>

/* --------------------------------- *
 * Use of the sizeof function *
 * --------------------------------- */

int main()  {
    
  /* declarations of some fundamental types */
  int a;
  unsigned int j;
  float b;
  double c;
  char d;
   

  /* assignment */
  a = 13;
  b = 1.321;
  c = 44.332211;
  d = 's';
  f = b;

  /* see their dimension */
  printf("bytes per int          : %d \n", sizeof(int));
  printf("bytes per int          : %d \n", sizeof(a));
  
  printf("bytes per unsigned int : %d \n", sizeof(unsigned int));
  printf("bytes per unsigned int : %d \n", sizeof(j));
  
  printf("bytes per float        : %d \n", sizeof(float));
  printf("bytes per float        : %d \n", sizeof(b));
  
  printf("bytes per double       : %d \n", sizeof(double));
  printf("bytes per double       : %d \n", sizeof(c));
  
  printf("bytes per char         : %d \n", sizeof(char));
  printf("bytes per char         : %d \n", sizeof(d));
  
  printf("bytes per long int: %d \n",    sizeof(long int));
  printf("bytes per long double: %d \n", sizeof(long double));


  /* see their address */
  printf("address of a: %d \n", &a);
  printf("address of a: %d \n", (long int) &a);
  printf("address of b: %d \n", (long int) &b);
  printf("address of c: %d \n", (long int) &c);
  printf("address of d: %d \n", (long int) &d);
  printf("address of f: %d \n", (long int) &f);

  
}


/*
address of a: -1073745068
address of b: -1073745072
address of c: -1073745080
address of d: -1073745081
address of e: -1073745088
address of f: -1073745092

 
Note:
- The keyword sizeof(...) returns the number of bytes of the argument
- It works both with types and with variables
- variables (nomi simbolici): a-z, A-Z, 0-9 (ma non come primo carattere)
- data types: int, float, double, char
- &: address operator
- &a: memory address of a
*/


