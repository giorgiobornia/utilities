/* GESTIONE DI LISTA ORDINATA
   Operazioni di inserimento, eliminazione e visualizzazione.
   Utilizza una lista lineare per implementare la pila        */

#include <stdio.h>
#include<malloc.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

void gestioneLista(void);
struct elemento *inserimento(struct elemento *);
struct elemento *eliminazione(struct elemento *);
void visualizzazione(struct elemento *);

main()
{
  gestioneLista();
}


void gestioneLista(void)
{
struct elemento *puntLista = NULL;
int scelta = -1;
char pausa;

while(scelta!=0) {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\tGESTIONE DI UNA SEQUENZA DI VALORI ORDINATI\n");
  printf("\t\t     MEDIANTE UNA STRUTTURA A LISTA");
  printf("\n\n\n\t\t\t 1. Per inserire un elemento");
  printf("\n\n\t\t\t 2. Per eliminare un elemento");
  printf("\n\n\t\t\t 3. Per visualizzare la lista");
  printf("\n\n\t\t\t 0. Per finire");
  printf("\n\n\n\t\t\t\t Scegliere una opzione: ");
  scanf("%d", &scelta);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  switch(scelta) {
     case 1:
        puntLista = inserimento(puntLista);
        break;
     case 2:
        puntLista = eliminazione(puntLista);
        break;
     case 3:
        visualizzazione(puntLista);
        printf("\n\nPremere un tasto per continuare...");
        scanf("%c%c", &pausa, &pausa);
        break;
  }
}
}


/* Visualizzazione della lista */
void visualizzazione(struct elemento *p)
{
struct elemento *paus = p;

printf("\npuntLista---> ");
while(paus!=NULL) {
  printf("%d---> ", paus->inf);
  paus = paus->pun;
}
printf("NULL");
}


/* Inserimento del valore passato dall'utente nella lista
   mantenendo l'ordinamento                               */
struct elemento *inserimento(struct elemento *p)
{
struct elemento *p0, *p1;
int posizione;

/* Creazione elemento */
p0 = (struct elemento *)malloc(sizeof(struct elemento));

printf("\nInserire l'informazione (un numero intero): ");
scanf("%d", &p0->inf);  

if(p==NULL) {           /* se la lista è vuota, l'elemento      */
  p = p0;               /* diventa il primo e unico della lista */
  p->pun = NULL;
}
else {
  if(p->inf > p0->inf) {    /* se il valore dell'elemento è  */
     p0->pun = p;           /* inferiore al primo l'elemento */
     p = p0;                /* diventa il primo della lista  */
  }
  else {           /* ricerca della posizione di inserimento */
     p1 = p;
     posizione = 0;
     while(p1->pun!=NULL && posizione!=1) {
       if(p1->pun->inf < p0->inf)
         p1 = p1->pun;          /* scorre in avanti p1       */
       else
         posizione = 1;         /* interrompe lo scorrimento */
     }
     p0->pun = p1->pun; /* connessione all'elemento successivo */
     p1->pun = p0;     /* connessione dall'elemento precedente */
  }
}
return(p);    /* ritorno del puntatore all'inizio della lista */
}


/* Eliminazione dell'elemento richiesto dalla lista ordinata */
struct elemento *eliminazione(struct elemento *p)
{
struct elemento *p1 = p, *p2;
struct elemento e;
int posizione = 0;
char pausa;

printf("\nInserire l'informazione da eliminare: ");
scanf("%d", &e.inf);

if(p1!=NULL) {              /* se la lista è vuota fine */
  if(p1->inf == e.inf) {    /* se è il primo da eliminare */
    p2 = p1;               
    p = p->pun;       /* si modifica il puntatore alla testa  */
    free(p2);
    return(p);
  }
  else {               /* ricerca dell'elemento da eliminare */
    while(p1->pun!=NULL && posizione!=1) {
       if(p1->pun->inf!=e.inf)
          p1 = p1->pun;          /* scorre in avanti p1 */
       else {
          posizione = 1;         /* interrompe lo scorrimento */
          p2 = p1->pun;
          p1->pun = p1->pun->pun;    /* eliminazione elemento */
          free(p2);                  /* libera la memoria */
         return( p );
       }
    }
  }
}

if(!posizione) {
  printf("\nElemento non incontrato nella lista ");
  scanf("%c%c", &pausa, &pausa);
}
return(p);
}
