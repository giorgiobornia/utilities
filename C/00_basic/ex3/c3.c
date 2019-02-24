/* #include <math.h> */
#include <stdio.h>
#include "mio.h"
/* --------------------------------- *
 * Scrittura e compilazione di c3.c: *
 * funzioni matematiche e librerie   *
 * --------------------------------- */
main()

{
  /* dichiarazione delle variabili */
  int sum;
  float a,b;
  double c;

  /* assegnazione */
  sum = 20 + constint;
  printf("la somma di 20 e constint e':");
  printf(" %15d \n\n",sum);

  printf("la somma di 20 e %1d e':",constint);
  printf(" %15d \n\n",sum);
  b = acosf(0.0);
  a = sinf(b);
  printf("1- pigreco (float)        :");
  printf(" %.6f \n",2.*b);
  printf("   il seno di 90° e' : %.6f \n",
	 a);

  c = b; /* float to double */
  printf("2- pigreco (float->double):");
  printf(" %.14f \n",2.*c);
  c = sin(c);
  printf("   il seno di 90° e' : %.14f \n",
	 c);

  c = acos(0.0);
  printf("3- pigreco (double)       :");
  printf(" %.14f \n",2.*c);
  c = sin(c);
  printf("   il seno di 90° e' : %.14f \n",
	 c);

}


