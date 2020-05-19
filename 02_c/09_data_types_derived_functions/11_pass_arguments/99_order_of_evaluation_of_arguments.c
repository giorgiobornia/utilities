#include <stdio.h>

/* First arguments to the right are evaluated, then to the left */

/* le espressioni passate come
argomenti alle funzioni sono prima valutate, ed il risultato della
valutazione viene scritto sullo stack per essere disponibile al codice che
implementa la funzione stessa.
Sorgono due problemi:
- in che ordine vengono valutate le espressioni ?
- in che ordine vengono scritti sullo stack i risultati delle valutazioni ?
La risposta alle due domande è la stessa:
vengono prima valutate (e il risultato scritto sullo stack) le
espressioni passate come ultimo argomento della funzione (le più a
destra), e poi via via quelle più a sinistra.
*/


void print3( int a, int b, int c) {
  printf("a=%d b=%d c=%d\n", a, b, c);
  printf("&a=%p &b=%p &c=%p\n", &a, &b, &c);
}


int main() {

int x=0;

print3 (x++, x++, x++);

return 0;

}
