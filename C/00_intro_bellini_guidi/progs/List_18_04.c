/* Creazione di un albero e visita in ordine anticipato.
   L'albero viene immesso dall'utente informa parentetica
   anticipata. L'etichetta dei nodi è un carattere. 
   L'albero è implementato con liste multiple             */

#include <stdio.h>
#include<stddef.h>

struct nodo {
  char inf;
  struct nodo *figlio;
  struct nodo *pArco;
};

struct nodo *albero();
struct nodo *creaAlbero(struct nodo *);
void anticipato(struct nodo *);

main()
{
struct nodo *radice;
radice = albero();                /* creazione dell'albero */
printf("\nVISITA IN ORDINE ANTICIPATO\n");
anticipato(radice);
}


/* Legge il primo carattere della rappresentazione parentetica
   e invoca la funzione creaAlbero()                         */
struct nodo *albero()
{
struct nodo *p = NULL;
char car;

printf("\nInserire la rappresentazione dell'albero: ");
scanf("%c", &car);
p = creaAlbero(p);
return(p);   /* ritorna il puntatore alla radice al chiamante */
}


/* Crea un nodo e vi inserisce la relativa etichetta. Per ogni figlio crea un arco. Invoca ricorsivamente se stessa          */
struct nodo *creaAlbero(struct nodo *p)
{
struct nodo *paus;
char car;

/* Crea il nodo */
p = (struct nodo *) malloc( sizeof(struct nodo) );
scanf("%c", &p->inf);       /* inserimento del valore nel nodo */
paus = p;
scanf("%c", &car);          /* lettura del carattere successivo */

while(car=='(') {           /* per ogni figlio ripeti */
  /* Crea l'arco */
  paus->pArco = (struct nodo *) malloc(sizeof(struct nodo));
  paus = paus->pArco;
 /* Invoca se stessa passando il campo figlio dell'elem. creato */
  paus->figlio = creaAlbero(paus->figlio);

  scanf("%c", &car);        /* lettura del carattere successivo */
}

paus->pArco = NULL;
return(p);     /* ritorna il puntatore alla radice al chiamante */
}


/* Visita ricorsivamente l'albero in ordine anticipato */
void anticipato(struct nodo *p)
{
printf("(%c", p->inf);
p = p->pArco;

while(p!=NULL) {
  anticipato(p->figlio);
  p = p->pArco;
}
printf(")");
}
