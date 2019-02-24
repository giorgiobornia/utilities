#include <stdio.h>
#include <math.h>

/*What is the smallest representable number*/



int main () {

 double a;
  
  a=1.;

  
  while (a > 0.)
    {

   a /= 10.;
      printf("%.15E\n",a);

   }

   printf("%.15E\n",a);

return 0;
}

/*

 *- Esempio di UNDERFLOW min 10e-325,10e-325 (sembra lo stesso per tutti)
 
 * Calcolo di overflow 
 E' inutile visualizzare piu' di ~7 cifre significative per i float
                         piu' di ~16 cifre significative per i double
 
                        */