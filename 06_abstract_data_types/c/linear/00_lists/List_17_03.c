/* Crea due liste e le visualizza. 
 * Addiziona gli elementi corrispondenti delle due liste, 
 * inserisce il risultato in una terza lista 
 * e la visualizza                        */

#include <stdio.h>
#include <malloc.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

struct elemento *creaLista2();
void visualizzaLista(struct elemento *);
struct elemento *sommaListe(struct elemento *,struct elemento *);

int main() {
    
struct elemento *puntLista1, *puntLista2, *puntLista3;

printf("\n PRIMA LISTA \n");
puntLista1 = creaLista2();

printf("\n SECONDA LISTA \n");
puntLista2 = creaLista2();

visualizzaLista(puntLista1);
visualizzaLista(puntLista2);

/* Invocazione della funzione per la somma delle liste */
puntLista3 = sommaListe(puntLista1, puntLista2);

/* Visualizzazione della lista somma delle precedenti  */
visualizzaLista(puntLista3);

}


/*  Addiziona gli elementi corrispondenti di due liste
e inserisce il risultato in una terza lista            */
struct elemento *sommaListe(struct elemento *p1, struct elemento *p2)
{
struct elemento *p3 = NULL, *p3aus;

if(p1!=NULL && p2!=NULL) {
 /* Creazione primo elemento  */
 p3 = (struct elemento *)malloc(sizeof(struct elemento));
 p3->inf = p1->inf + p2->inf;             /* somma */
 p3aus = p3;              /* p3aus punta III lista */
 p1 = p1->pun;            /* scorrimento I lista   */
 p2 = p2->pun;            /* scorrimento II lista  */

 /* Creazione elementi successivi */
 for(; p1!=NULL && p2!=NULL;) {
  p3aus->pun = (struct elemento *)malloc(sizeof(struct elemento));
  p3aus = p3aus->pun;     /* scorrimento III lista */
  p3aus->inf = p1->inf + p2->inf;         /* somma */
  p1 = p1->pun;           /* scorrimento I lista   */
  p2 = p2->pun;           /* scorrimento II lista  */
 }
 p3aus->pun = NULL;     /* marca di fine III lista */
}
return(p3);             /* ritorno del puntatore alla III lista */
}

/* ATTENZIONE: devono essere aggiunte le definizioni delle
   funzioni per creare - creaLista2() - e visualizzare
   - visualizzaLista() - la lista,
   presenti nel precedente Listato 17.2                    */
