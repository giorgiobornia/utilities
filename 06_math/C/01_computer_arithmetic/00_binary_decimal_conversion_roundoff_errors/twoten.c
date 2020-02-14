#include <stdio.h>



int main() {

 float a;

//   a = 0.25;
  a = 0.5;
//   a = 0.1;
  
   printf("%.6e\n", a);
   printf("%.10e\n", a);
   printf("%.16e\n", a);
   printf("%.50e\n", a);

  a = 2.1;
  
   printf("%.6e\n", a);
   printf("%.10e\n", a);
   printf("%.16e\n", a);
   printf("%.50e\n", a);

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
