/* GESTIONE DI UNA PILA
   Operazioni di inserimento, eliminazione
   e visualizzazione. Utilizza un array di strutture
   per implementare la pila                          */

#include <stdio.h>
#include <malloc.h>

#define LUN_PILA 10

void gestionePila(void);
inserimento(int *, int *, int);
eliminazione(int *, int *, int *);
pilaVuota(int);
void visualizzazionePila(int *, int);

main()
{
gestionePila();
}


void gestionePila(void)
{
int pila[LUN_PILA];
int puntTesta = 0;
int scelta = -1, ele;
char pausa;

while(scelta!=0) {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\tESEMPIO UTILIZZO STRUTTURA ASTRATTA: PILA");
  printf("\n\n\n\t\t\t 1. Per inserire un elemento");
  printf("\n\n\t\t\t 2. Per eliminare un elemento");
  printf("\n\n\t\t\t 3. Per visualizzare la pila");
  printf("\n\n\t\t\t 0. Per finire");
  printf("\n\n\n\t\t\t\t Scegliere una opzione: ");
  scanf("%d", &scelta);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  switch( scelta ) {
    case 1:
       if(puntTesta >= LUN_PILA) {
          printf("Inserimento impossibile: ");
          printf("memoria disponibile terminata");
          printf("\n\n Premere un tasto per continuare...");
          scanf("%c%c", &pausa, &pausa);
       }
       else {
          printf("Inserire un elemento: ");
          scanf("%d", &ele);
          puntTesta = inserimento(pila, &puntTesta, ele);
       }
       break;
    case 2:
       if(pilaVuota(puntTesta)) {
          printf("Eliminazione impossibile: pila vuota");
          printf("\n\n Premere un tasto per continuare...");
          scanf("%c%c", &pausa, &pausa);
       }
       else {
          puntTesta = eliminazione(pila, &puntTesta, &ele);
          printf("Eliminato: %d", ele );
          printf("\n\n Premere un tasto per continuare...");
          scanf("%c%c", &pausa, &pausa);
       }
       break;
    case 3:
       visualizzazionePila(pila, puntTesta);
       printf("\n\n Premere un tasto per continuare...");
       scanf("%c%c", &pausa, &pausa);
       break;
  }
}
}


void visualizzazionePila(int *pila, int p)
{
printf("\n<------ Testa della pila ");
while(p>=1)
  printf("\n%d", pila[--p]);
}


inserimento(int *pila, int *p, int ele)
{
pila[*p] = ele;
++*p;
return(*p);
}


eliminazione(int *pila, int *p, int *ele)
{
--*p;
*ele = pila[*p];
return(*p);
}


int pilaVuota(int p)
{
if(p==0)
  return(1);
else
  return(0);
}
