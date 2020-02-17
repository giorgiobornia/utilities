#include <stdio.h>

#define OP +

// #define MYTYPE float  //no difference is shown... how is it possible that with lower precision you don't have differences...
#define MYTYPE double  //there are differences

int main() {

 MYTYPE a, b, c, s_1, s_2;

   a = 0.7;
   b = 0.2;
   c = 0.1;

   a = 7.;
   b = 2.;
   c = 1.;
   
//  these three are sums of powers of 2, so no roundoff error here   
//    a = 0.25;
//    b = 0.75;
//    c = 0.5;

   s_1 = a OP (b OP c);
   s_2 = (a OP b) OP c;
   
  
   printf("%.6e\n", s_1);
   printf("%.10e\n", s_1);
   printf("%.16e\n", s_1);
   printf("%.50e\n", s_1);

   printf("%.6e\n", s_2);
   printf("%.10e\n", s_2);
   printf("%.16e\n", s_2);
   printf("%.50e\n", s_2);
   

return 0;
}


/* Base conversion
 * try float a or double a
 * scan %f or %lf
 * show that for %.6f or %.30f you get different roundings
 * Chiaramente la funzione printf deve riconvertire dalla base 2 verso la base 10
  La funzione printf fara' conversioni da BASE 2 a BASE 10 e poi arrotondamento
  al numero di cifre significative richieste in base 10.
   Prende il numero che c'e' nel registro, affetto da errore di arrotondamento, e lo converte. 
   Anche l'operazione di conversione introduce in generale un errore di arrotondamento. 
   
   Es. inserisco 0.1 lui lo converte in BASE2 => errore
 
  - se metti e o f le cose CAMBIANO, perche'
 */
