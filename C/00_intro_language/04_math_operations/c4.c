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




/*
raus@birillo -->
raus@birillo --> ./c4
a,b,c: 25 2 120
d,e  : 2.500000e+01 2.000000

a/b*b: 24
d/e*e: 25.000000
c/a  : 4
c/d  : 858993459
c/a  : 858993459
c/a  : 0
3.2**2.1     : 11.503100
3.2**2.1     : 11.503100
3.2**2       : 10.240001
3.2**2.      : 10.240001
a%b   : 1
26%3  : 2
raus@birillo -->

Note:
- attenzione alle operazioni, agli operandi
  e alle conversioni fra operandi misti!

- powf(x,y): e' l'elevamento a potenza,
  prende il float x e l'eleva all'esponente 
  float y. 
  extern float powf (float __x, float __y);
  Fare molta attenzione: powf(3.2,2) su 
  alcuni sistemi puo' essere assai diverso 
  da powf(3.2,2.), bisogna vedere se il 
  sistema lo converte il float subito o meno.

- operatori binari: +,-,*,/,%
- operatori unari: +,-*/


