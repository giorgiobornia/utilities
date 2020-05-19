 
#include <stdio.h>

main(int argc, char *argv[]) 
/* argc: argument count (n. argomenti+1) */
/* argv: argument vector (puntatore ad */
/* un vettore di stringhe che contiene */
/* gli argomenti). */
{
int i;
for(i=1; i<argc; i++)
printf("%s",argv[i]);
printf("\n");
return 0;
}


// Il programma precedente emula il comando Unix echo, nel senso che accetta
// un numero arbitrario di comandi e li stampa sullo standard output.
