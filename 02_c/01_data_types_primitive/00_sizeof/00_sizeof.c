#include <stdio.h>

/* --------------------------------- *
 * Use of the sizeof function *
 * --------------------------------- */

int main()  {
    
  /* declarations of some fundamental types */
  int a;
  unsigned int j;
  float b;
  float f;
  double c;
  char d;
   

  /* assignment */
  a = 13;
  b = 1.321;
  c = 44.332211;
  d = 's'; /* single quotes, not double quotes! */
  f = b;

  /* print their values */
  printf("Correct format specifiers\n");
      
  printf("int    a:       %d \n", a);
  printf("unsigned int j: %u \n", j);
  printf("float  b: %e \n", b);
  printf("double c: %e \n", c);
  printf("char   d: %c \n", d);
  printf("float  f: %e \n", f);
  
  printf("Mismatched format specifiers: you will get complete errors!\n");
  
  printf("int    a:       %f \n", a);
  printf("unsigned int j: %d \n", j);
  printf("float  b: %d \n", b);
  printf("double c: %d \n", c);
//   printf("char   d: %s \n", d);  /*seg fault*/
  printf("char   d: %d \n", d);
  printf("float  f: %d \n", f);

  
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
  
  printf("bytes per long int: %d \n",    sizeof(long int));
  printf("bytes per long double: %d \n", sizeof(long double));
//   printf("bytes per long char: %d \n",   sizeof(long char));  /*does not exist*/

  /* other types of variables */
  printf("\n");
  printf("bytes per long int: %d \n",     sizeof(long int));
  printf("bytes per short int: %d \n",    sizeof(short int));
  printf("bytes per unsigned int: %d \n", sizeof(unsigned int));
  
//   printf("bytes per long int: %d \n",     sizeof(long double));   /* exists */
//   printf("bytes per short int: %d \n",    sizeof(short double));  /*does not exist*/
//   printf("bytes per unsigned int: %d \n", sizeof(unsigned double));  /*does not exist*/

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


