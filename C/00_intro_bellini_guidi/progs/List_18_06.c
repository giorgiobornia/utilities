/* Dalla rappresentazione parentetica di un albero ricava il
   corrispondente albero binario, che visita in ordine simmetrico,
   anticipato e differito.
   Per la creazione usa una funzione iterativa (non ricorsiva)
   con l'ausilio di una pila gestita mediante una lista lineare
   il cui campo inf e' un puntatore ai nodi dell'albero binario.
   Per le  visite in ordine simmetrico, anticipato e differito
   rimangono valide le funzioni ricorsive già esaminate           */

#include <stdio.h>
#include <stddef.h>

struct nodo {                  /* nodo dell'albero binario */
  char inf;
  struct nodo *albSin;
  struct nodo *albDes;
};

struct nodo *albBinPar();    /* funzione per la creazione */

void anticipato(struct nodo *);         /* visite */
void simmetrico(struct nodo *);
void differito(struct nodo *);

                               
struct elemento {             /* elemento della lista lineare  */
  struct nodo     *inf;       /* con cui e' implementata la pila */
  struct elemento *pun;
};

/* Funzioni per la gestione della pila */
struct elemento *inserimento(struct elemento *, struct nodo *);
struct elemento *eliminazione(struct elemento *, struct nodo **);
int pilaVuota(struct elemento *);

main()
{
struct nodo *radice;

radice = albBinPar();

printf("\nVISITA IN ORDINE SIMMETRICO\n");
simmetrico(radice);
printf("\nVISITA IN ORDINE ANTICIPATO\n");
anticipato(radice);
printf("\nVISITA IN ORDINE DIFFERITO\n");
differito(radice);
}


/* Dalla rappresentazione parentetica di un albero crea
   il corrispondente albero binario                      */
struct nodo *albBinPar()
{
struct nodo *p;
struct nodo *paus, *pp;
char car;
int logica = 1;

struct elemento *puntTesta = NULL;    /* inizializzazione pila */

printf("\nInserire la rappresentazione dell'albero: ");
scanf("%c", &car);

/* Creazione della radice */
p = (struct nodo *) malloc(sizeof(struct nodo));

scanf("%c", &p->inf);

p->albSin = NULL;     /* inizializzazione dei puntatori */
p->albDes = NULL;     /* ai sottoalberi */

paus = p;  logica = 1;

do {
  scanf("%c", &car);
  if(car=='(') {
    pp = (struct nodo *) malloc(sizeof(struct nodo));
    scanf("%c", &pp->inf);
    pp->albSin = NULL;
    pp->albDes = NULL;
    if(logica) {
      paus->albSin = pp;
      /* Inserimento in pila */
      puntTesta = inserimento(puntTesta, paus);
    }
    else {
      paus->albDes = pp;
      logica = 1;
    }
    paus = pp;
   }
   else
     if(logica)
       logica = 0;
     else
       /* Eliminazione dalla pila */
       puntTesta = eliminazione(puntTesta, &paus);
}
while(!pilaVuota(puntTesta));

return(p);
}


/* Funzioni per la gestione della pila */

struct elemento *inserimento(struct elemento *p, struct nodo *ele)
{
struct elemento *paus;

paus = (struct elemento *)malloc(sizeof(struct elemento));
if(paus==NULL) return(NULL);

paus->pun = p;
p = paus;
p->inf = ele;

return(p);
}


struct elemento *eliminazione(struct elemento *p, struct nodo **ele)
{
struct elemento *paus;

*ele = p->inf;
paus = p;
p = p->pun;
free(paus);

return(p);
}


int pilaVuota(struct elemento *p)
{
if(p ==NULL)
  return(1);
else
  return(0);
}


/* DEVONO ESSERE INCLUSE LE FUNZIONI RICORSIVE DI VISITA DELL'ALBERO BINARIO GIÀ ESAMINATE, DOVE IL VALORE VISUALIZZATO È DI TIPO CHAR /*
...
