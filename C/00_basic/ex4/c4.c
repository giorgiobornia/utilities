#include <math.h>
/* ------------------------------------ *
 * Scrittura e compilazione di c4.c:    *
 * espressioni aritmetiche (+,-,*,/,%)  *
 * ------------------------------------ */
main()

{
  /* dichiarazione delle variabili */
  int a,b,c,f;
  float d,e;

  /* assegnazione */
  a =  +25;
  b =   2;
  c = 120;
  d = 25.;
  e =  2.;
  f = -3;

  printf("a,b,c,f: %d %d %d %d\n",a,b,c,f);
  printf("d,e    : %e %f \n\n",d,e);

  printf("a/b*b: %d\n",a/b*b);
  printf("d/e*e: %f\n",d/e*e);

  printf("c/a  : %d\n", c/a);
  printf("c/d  : %f\n", c/d);

  printf("c/a  : %f\n", (float) c/a);
  printf("c/a  : %f\n", (float) (c/a));

  /* elevamento a potenza x**y o x^y 
     attraverso la funzione:
     float powf (float x, float y) */

  printf("3.2**2.1     : %f\n", powf(3.2,2.1) );
  printf("3.2**2.1     : %f\n", powf(3.2,2+.1) );
  printf("3.2**2       : %f\n", powf(3.2,2));
  printf("3.2**2.      : %f\n", powf(3.2,2.));

  /* modulus: a%b, da il resto della divisione
     fra due interi */
  printf("a%%b   : %d\n",a%b);
  printf("26%%3  : %d\n",26%3);
}


