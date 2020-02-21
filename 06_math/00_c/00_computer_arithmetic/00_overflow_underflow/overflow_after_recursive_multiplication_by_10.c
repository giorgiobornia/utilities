#include <stdio.h>
#include <math.h>

/*What is the highest representable number*/


int main() {

 float a;
  
  a = 1.;
  
  while (a < 1.e39)
    {

   a *= 10.;
  
      printf("%.15E\n",a);

   }

   printf("%.15E\n",a);

return 0;

}


/*
 *- Esempio di OVERFLOW max 10e38,10e307
 *- Esempio di UNDERFLOW min 10e-325,10e-325 (sembra lo stesso per tutti)
 
 *- Colgo l'occasione di questi esempi per spiegare la FORMATTAZIONE di "printf" e "scanf"

 *- File IO
 *-Un esempio di cancellazione numerica legato o meno all'equazione di secondo grado
 
 
 
 * Calcolo di overflow 
 E' inutile visualizzare piu' di ~7 cifre significative per i float
                         piu' di ~16 cifre significative per i double
 
 La funzione printf non fa arrotondamenti, fa solo conversioni da BASE 2 a BASE 10.
   Prende il numero che c'e' nel registro, affetto da errore di arrotondamento,
   e lo converte. Anche l'operazione di conversione introduce in generale un errore di 
   arrotondamento. Es. inserisco 0.1
                       lui lo converte in BASE2 => errore
                       poi gli dico di stamparlo, quindi 
                         */
