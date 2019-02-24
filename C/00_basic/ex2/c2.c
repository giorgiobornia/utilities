#include <stdio.h>
/* --------------------------------- *
 * Scrittura e compilazione di c2.c: *
 * varie variabili e loro dimensione * 
 * --------------------------------- */
int main()

{
  /* dichiarazione di un intero, un float,
     un double e un carattere */
  int a;
  float b;
  double c;
  char d;
  /*
  char d,s;
  */
  int e;
  float f;

  /* assegnazione di un valore */
  a = 13;
  b = 1.321;
  c = 44.332211;
  d = 's';
  e = 23;
  f = b;

  /* stampiamo i loro valori */
  printf("intero a: %2d \n",a);
  printf("reale  b: %e \n",b);
  printf("doppia prec. c: %e \n",c);
  printf("carattere    d: %c \n",d);
  printf("intero e: %2d \n",e);
  printf("reale  f: %e \n",f);

  /* vediamo la loro dimensione */
  printf("\nbytes per intero: %d \n",
	 sizeof(int));
  printf("bytes per intero: %d \n",
	 sizeof(a));
  printf("bytes per float : %d \n",
	 sizeof(b));
  printf("bytes per double: %d \n",
	 sizeof(c));
  printf("bytes per char  : %d \n",
	 sizeof(char));
  printf("bytes per char  : %d \n",
	 sizeof(d));

  /* vediamo il loro indirizzo */
  printf("indirizzo di a: %d \n",(int) &a);
  printf("indirizzo di b: %ld \n",(long int) &b);
  printf("indirizzo di c: %d \n",(int) &c);
  printf("indirizzo di d: %d \n",(int) &d);
  /*
  printf("indirizzo di s: %ld \n",&s);

  printf("indirizzo di e: %d \n",&e);
  printf("indirizzo di f: %d \n",&f);
  */
  /* altri tipi di variabile */
  printf("\nbytes per long int: %d \n",
	 sizeof(long int));
  printf("bytes per short int: %d \n",
	 sizeof(short int));
  printf("bytes per unsigned int: %d \n",
	 sizeof(unsigned int));
}
