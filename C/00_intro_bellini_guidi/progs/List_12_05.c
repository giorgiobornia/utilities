/*Programma ricorsivo per risolvere la torre di Hanoi*/

#include <stdio.h>

#define DISCHI 4
int mossa;

void hanoi(int, char, char, char);
void muovi(int, char, char);

main()
{
mossa = 0;
printf("\nMosse da eseguire per spostare %d dischi", DISCHI);
printf("\n---------------------------------------");
hanoi(DISCHI, 'A', 'B', 'C');/* Chiamata della procedura hanoi */
}

/* Funzione ricorsiva "hanoi" per spostare una torre di n
   dischi da pioloP a pioloA usando aus come piolo di ausilio */

void hanoi(int n, char pioloP, char pioloA, char aus)
{
if(n==1) muovi(1, pioloP, pioloA);
else {
  hanoi(n - 1, pioloP, aus, pioloA);
  muovi(n, pioloP, pioloA);
  hanoi(n - 1, aus, pioloA, pioloP);
}
}


/* Funzione "muovi" per spostare il disco nd
   dal piolo di partenza pP al piolo di arrivo pA*/

void muovi(int nd, char pP, char pA)
{
char invio;
mossa = mossa + 1;
printf("\n%3d",mossa);
printf(": muovere disco %d da %c a %c", nd, pP, pA);
scanf("%c", &invio);
}
