#include <stdio.h>

main(){
// viene assegnato un indirizzo, in esadecimale, alla variabile puntatore:
	char *charp = (char *) 0x0111;    
	int *intp = (int *) 0x0222;
	printf("charp: %lX,   intp: %lX\n",charp, intp);
//le variabili puntatore sono incrementate di 1:
	printf("charp: %lX,   intp: %lX\n",charp+1, intp+1);
}



// vedere come l'aritmetica dei puntatori dipenda dal tipo della variabile puntata.

// fare il watch di charp e intp

// modificare il programma cambiando i tipi di variabile puntata in modo da ritrovare quanto spazio di memoria è riservato ad altri tipi di dato semplice.
