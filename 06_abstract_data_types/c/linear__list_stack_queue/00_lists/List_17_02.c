/* Accetta in ingresso una sequenza di interi e li memorizza in una lista.
 * La sequenza termina quando viene immesso il valore zero.
 * La lista creata viene visualizzata. 
 * Determina il maggiore della lista     */

#include <stdio.h>
#include <malloc.h>
#include <limits.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

struct elemento *creaLista2();
void visualizzaLista(struct elemento *);
int maggioreLista(struct elemento *);

int main()
{
    
struct elemento *puntLista;   /* puntatore alla testa 
                                 della lista           */
puntLista = creaLista2();     /* chiamata funzione per
                                 creare la lista       */
visualizzaLista(puntLista);   /* chiamata funzione per
                                 visualizzare la lista */
/* Stampa il valore di ritorno della funzione maggioreLista() */
printf("\nIl maggiore e': %d\n\n", maggioreLista(puntLista));

}


/* Accetta in ingresso una sequenza  di interi e li 
   memorizza in una lista. Il numero di interi che compongono 
   la sequenza termina con il valore zero                     */
struct elemento *creaLista2()
{
struct elemento *p, *paus;
struct elemento x;

printf("\nInserisci un'informazione (0 per fine lista): ");
scanf("%d", &x.inf);

if(x.inf==0)  p = NULL;           /* lista vuota */
else {
/* Creazione del primo elemento */
 p = (struct elemento *)malloc(sizeof(struct elemento));

 p->inf = x.inf;
 paus=p;

 while(x.inf!=0) {
  printf("\nInserisci un'informazione (0 per fine lista): ");
  scanf("%d", &x.inf);
  if(x.inf!=0) {
   /* Creazione dell'elemento successivo */
   paus->pun = (struct elemento *)malloc(sizeof(struct elemento));

   paus = paus->pun;      /* attualizzazione di paus */
   paus->inf = x.inf;     /* inserimento dell'informazione
                             nell'elemento                 */
  }
  else
   paus->pun = NULL;      /* Marca di fine lista */
 }
}
return(p);
}


/* Determina il maggiore della lista. 
   Il parametro in ingresso è il puntatore alla testa */
maggioreLista(struct elemento *p)
{
int max = INT_MIN;

/* Ciclo di scansione della lista */
while(p != NULL) {
  if(p->inf > max)     
    max = p->inf;
  p = p->pun;             /* scorre di un elemento in avanti */
}
return(max);
}

/* Visualizza la lista */
void visualizzaLista(struct elemento *p)
{
printf("\npuntLista---> ");

/* Ciclo di scansione della lista */
while(p!=NULL) {          
  printf("%d", p->inf);    /* visualizza il campo informazione */
  printf("---> ");
  p = p->pun;              /* scorre di un elemento in avanti */
}
printf("NULL\n\n");
}
