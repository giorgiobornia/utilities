/* DA AGGIUNGERE ALLE DICHIARAZIONI INIZIALI DEL LISTATO 18.1 */

void simmetrico(struct nodo *);
void ricerca(struct nodo *, int, struct nodo **);

/* DA AGGIUNGERE AL MAIN DEL LISTATO 18.1 */

struct nodo *trovato;
int chi;
...
printf("\nVISITA IN ORDINE SIMMETRICO\n");
simmetrico(radice);

printf("\nInserire il valore da ricercare: ");
scanf("%d", &chi);

printf("\nRICERCA COMPLETA");
trovato = NULL;
ricerca(radice, chi, &trovato);
if(trovato != NULL)
  printf("\n Elemento %d presente \n", trovato->inf);
else
  printf("\n Elemento non presente\n");


/* Funzione che visita l'albero binario in ordine simmetrico.
   DA AGGIUNGERE AL LISTATO 18.1                              */

void simmetrico(struct nodo *p)
{
if(p!=NULL) {
  simmetrico(p->albSin);
  printf("%d  ", p->inf);
  simmetrico(p->albDes);
}
}


/* Funzione che ricerca un'etichetta nell'albero binario.
   DA AGGIUNGERE AL LISTATO 18.1.
   Visita l'albero in ordine anticipato                    */

void ricerca(struct nodo *p, int val, struct nodo **pEle)
{
if(p!=NULL)
  if(val == p->inf)      /* La ricerca ha dato esito positivo */
    *pEle = p;           /* pEle è passato per indirizzo
                            per cui l'assegnamento di p
                            avviene sul parametro attuale */
  else {
    ricerca(p->albSin, val, pEle);
    ricerca(p->albDes, val, pEle);
}
}
