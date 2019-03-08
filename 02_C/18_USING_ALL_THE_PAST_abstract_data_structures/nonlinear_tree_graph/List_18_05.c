/* DA AGGIUNGERE AL LISTATO 18.4 /*

...
struct nodo *trovato;
char sottoAlbero, invio;
...

scanf("%c", &invio);
printf("\nInserire la radice del sottoalbero: ");
scanf("%c", &sottoAlbero);

trovato = NULL;
ricerca(radice, sottoAlbero, &trovato);
if(trovato!=NULL) {
  printf("\n SOTTOALBERO IN ORDINE ANTICIPATO \n");
  anticipato(trovato);
}
else
  printf("\n Sottoalbero non presente");
}


/* Visita in ordine anticipato, ricercando il sottoalbero con
radice sa. Se lo reperisce assegna il suo indirizzo a *puntSa */

ricerca(struct nodo *p, char sa, struct nodo **puntSa)
{
if(sa == p->inf)
  *puntSa = p;
else
{
  p = p->pArco;
  while(p!=NULL) {
    ricerca(p->figlio, sa, puntSa);
    p = p->pArco;
  }
}
}
