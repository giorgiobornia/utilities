/* Accetta in ingresso una sequenza di interi e li memorizza in una lista.
 * Il numero di interi che compongono la sequenza è richiesto all'utente. 
 * La lista creata viene visualizzata   */

#include <stdio.h>
#include <malloc.h>

/* Struttura degli elementi della lista */
struct elemento {
  int inf;
  struct elemento *pun;
};

struct elemento *creaLista();
void visualizzaLista(struct elemento *);

int main()
{
    
struct elemento *puntLista;   /* puntatore alla testa della lista            */
puntLista = creaLista();      /* chiamata funzione per creare la lista       */
visualizzaLista(puntLista);   /* chiamata funzione per visualizzare la lista */
}


/* Funzione per l'accettazione dei valori immessi
   e la creazione della lista. Restituisce il puntatore alla testa */
struct elemento *creaLista()
{
struct elemento *p, *paus;
int i, n;

printf("\n Da quanti elementi e' composta la sequenza?  ");
scanf("%d", &n);

if(n==0)  p = NULL;           /* lista vuota */
else
{
  /* Creazione del primo elemento */
  p = (struct elemento *)malloc(sizeof(struct elemento));
  printf("\nInserisci la 1a informazione: ");
  scanf("%d", &p->inf);
  paus = p;

  /* Creazione degli elementi successivi */
  for(i=2; i<=n; i++) {
   paus->pun = (struct elemento *)malloc(sizeof(struct elemento));
   paus = paus->pun;
   printf("\nInserisci la %da informazione: ", i);
   scanf("%d", &paus->inf);
  }
  paus->pun = NULL;           /* marca di fine lista */
}
return(p);
}


/* Funzione per la visualizzazione della lista.
   Il parametro in ingresso è il puntatore alla testa */
void visualizzaLista(struct elemento *p)
{
printf("\npuntLista---> ");

/* Ciclo di scansione della lista */
while(p!=NULL) {
  printf("%d", p->inf);    /* visualizza il campo informazione */
  printf("---> ");
  p = p->pun;              /* scorri di un elemento in avanti  */
}
printf("NULL\n\n");
}
