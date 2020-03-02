#include <stdio.h>

/* --------------------------------- *
 * Use of the sizeof function *
 * --------------------------------- */

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
  printf("int    a: %2d \n",a);
  printf("float  b: %e \n",b);
  printf("double c: %e \n",c);
  printf("char   d: %c \n",d);
  printf("int    e: %2d \n",e);
  printf("float  f: %e \n",f);

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

  /* see their address */
  printf("address of a: %d \n", &a);
  printf("address of a: %d \n", (long int) &a);
  printf("address of b: %d \n", (long int) &b);
  printf("address of c: %d \n", (long int) &c);
  printf("address of d: %d \n", (long int) &d);
  printf("address of e: %d \n", (long int) &e);
  printf("address of f: %d \n", (long int) &f);

  
  /* other types of variables */
  printf("\n");
  printf("bytes per long int: %d \n", sizeof(long int));
  printf("bytes per short int: %d \n",  sizeof(short int));
  printf("bytes per unsigned int: %d \n", sizeof(unsigned int));
}


/*
address of a: -1073745068
address of b: -1073745072
address of c: -1073745080
address of d: -1073745081
address of e: -1073745088
address of f: -1073745092

 
Note:
- la funzione: sizeof(...) ritorna il numero di bytes dell'argomento
- variabili (nomi simbolici): a-z, A-Z, 0-9 (ma non come primo carattere)
- tipi di dati: int, float, double, char
- &: operatore indirizzo
- &a: indirizzo in memoria di a
*/


