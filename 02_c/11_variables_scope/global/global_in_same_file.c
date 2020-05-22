 
#include <stdio.h>


/* Problems with global variables inside the same translation unit */

int K = 2; /* variabile globale visibile da tutte le funzioni */


void funzione1();


int main() {
    
    int i = 34;

printf("i = %d \n", i );  /* stampa i cioè 34, corretto  */
 
printf("K = %d \n", K );  /* stampa K cioè 2, corretto */
printf("g = %f \n", g );  /* NON "VEDE" g, ERRORE */

funzione1();

return 0;

    
}


double  g=13;


void funzione1()
{
printf("g = %f \n", g );  /* stampa g, cioè 13, corretto */

printf("i = %d \n", i ); /* NON VEDE i, ERRORE */

}
