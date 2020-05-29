/* ------------------------------------ *
 * Arithmetic operators (+,-,*,/,%, pow)  *
 * pow for doubles
 * powf for floats
 * You can find the operator precedence and associativity rules in "man operator"
 * ------------------------------------ */


#include <stdio.h>
#include <math.h>


int main()

{
  /* variable declaration */
  int a, b, c, f;
  double d, e;

  
  /* assignment */
  c = 120;
  a =  +25;
  d = 25.;
  
  b =   2;
  e =  2.;
  
  f = -3;

  printf("a, b, c, f: %d %d %d %d\n", a, b, c, f);
  printf("d, e    : %e %f \n\n", d, e);

  printf("Divide then multiply\n");
  
  printf("a/b*b: %25.16d\n", a/b*b);
  printf("d/e*e: %25.16f\n", d/e*e);

   /* Division between integers */
   
  printf("%f\n", e);
  printf("%f\n", c); /* It seems like he is taking the last %f printed */
  printf("%d\n", c); 
  printf("int    / int   : with int formatting     c/a : %d\n", c/a);
  printf("int    / int   : with double formatting  c/a : %f\n", c/a);
  printf("double / int   : with double formatting  c/a : %f\n", (double) c/a);
  printf("double / int   : with double formatting  c/a : %f\n", ( (double) c )/a);
  printf("int    / double: with double formatting  c/a : %f\n", c /( (double) a));
  printf("c/a  : %f\n", (double) (c/a));

  printf("c/d  : %f\n", c/d);
  
    
  /* exponentiation: x**y o x^y 
     through the function:
     double pow (double x, double y) */

  printf("Exponentiation\n");
  
  printf("3.2**2.1     : %f\n", pow(3.2,2.1) );
  printf("3.2**2.1     : %f\n", pow(3.2,2+.1) );
  printf("3.2**2       : %f\n", pow(3.2,2));
  printf("3.2**2.      : %f\n", pow(3.2,2.));

  printf("Modulus\n");

  /* modulus: a%b, yields the remainder of the division between two integers */
  printf("a%%b   : %d\n", a%b);
  printf("26%%3  : %d\n", 26%3);
}




/*

./c4
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
- attenzione alle operazioni, agli operandi e alle conversioni fra operandi misti!

- pow(x,y): e' l'elevamento a potenza,
  prende il double x e lo eleva all'esponente double y. 
  extern double pow (double __x, double __y);
  Fare molta attenzione: pow(3.2,2) su 
  alcuni sistemi puo' essere assai diverso 
  da pow(3.2,2.), bisogna vedere se il 
  sistema lo converte il double subito o meno.

- operatori binari: +,-,*,/,%

- operatori unari: +,-*/
