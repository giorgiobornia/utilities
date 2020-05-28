#include <stdio.h>

// Problemi di sconfinamento
// 
// • se si accede in lettura al vettore fuori da esso può accadere, a seconda del
// sistema operativo:
// • nessun problema apparante, solo errore logico
// • segmentation fault.
// • se invece si accede in scrittura al vettore ci saranno danni maggiori,
// perchè oltre ai due problemi già citati si sovrascriverà una locazione di
// memoria che potrebbe contenere dati essenziali al programma o peggio
// ancora al sistema perativo. Nel caso peggiore, ad es. sovrascrittura del
// vettore degli interrupt, si può arrivare al blocco del sistema.
// Oppure si modificherà il valore delle variabili dichiarate immediatamente
// sopra o sotto al vettore.


int main(void)
{
    
int bottom_of_the_stack = 0;
int vet[10];
int top_of_the_stack = 0;

// This program was assuming that these variables were contiguously piling up in the stack,
// like this:

// top_of_the_stack
//    vet[0]
//      .
//      .
//      .
//    vet[9]
// bottom_of_the_stack

// However, it doesn't seem so! Just print the pointers and you'll find out!

printf("INIZIO: prima=%d dopo=%d\n", bottom_of_the_stack, top_of_the_stack );

 for (int i = -1; i <= 10; i++) {
  vet[i] = 99;
   printf("i=%d prima=%d dopo=%d\n", i, bottom_of_the_stack, top_of_the_stack );
  }

}
