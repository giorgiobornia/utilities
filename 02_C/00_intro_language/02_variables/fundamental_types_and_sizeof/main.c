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


/*
raus:--> gcc -o c2 c2.c
raus:--> c2
intero a: 13
reale  b: 1.321000e+00
doppia prec. c: 4.433221e+01
carattere    d: s
intero e: 23
reale  f: 1.321000e+00

bytes per intero: 4
bytes per intero: 4
bytes per float : 4
bytes per double: 8
bytes per char  : 1
bytes per char  : 1
indirizzo di a: -1073745068
indirizzo di b: -1073745072
indirizzo di c: -1073745080
indirizzo di d: -1073745081
indirizzo di e: -1073745088
indirizzo di f: -1073745092

bytes per long int: 4
bytes per short int: 2
bytes per unsigned int: 4
raus:--> 
Note:
- la funzione: sizeof(...) ritorna
  il numero di bytes dell'argomento
- variabili (nomi simbolici): a-z, A-Z, 
  0-9 (ma non come primo carattere)
- tipi di dati: int, float, double, char
- &: operatore indirizzo
- &a: indirizzo in memoria di a
*/


