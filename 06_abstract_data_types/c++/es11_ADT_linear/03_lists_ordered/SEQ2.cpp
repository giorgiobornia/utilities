/*
  Name: seq2.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					Effettua la ricerca di un dato in una sequenza ordinata crescente e lo elimina - Es 2
*/

#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
	 tipoValore value;
	 struct elemento *next;
} nodo;

typedef nodo *seqOrd;

seqOrd ins(tipoValore, seqOrd);
seqOrd del(tipoValore, seqOrd);

seqOrd leggi();
void visualizza(seqOrd);

main() {
  seqOrd l=leggi();
  visualizza(l);
  printf("\nQuale elemento da cancellare? \t");
  tipoValore elem;
  scanf("%d", &elem);
  visualizza(del(elem,l));
}

seqOrd ins(tipoValore ele, seqOrd lst){
	seqOrd lstAus=(seqOrd) malloc(sizeof(nodo));
	lstAus->value=ele;
	if (lst!=NULL && ele>lst->value){
		seqOrd lst1=lst, lst2=lst->next;
		while (lst2!=NULL && ele>lst2->value){
			lst1=lst2;
			lst2=lst2->next;
		}
		lstAus->next=lst2;
		lst1->next=lstAus;
	}else{
			lstAus->next=lst;
			lst=lstAus;
	}
	return lst;
}

seqOrd del(tipoValore ele, seqOrd lst){
	if (lst!=NULL && ele>=lst->value)
		if (ele==lst->value)
				while (lst!=NULL && ele==lst->value)
						lst=lst->next;
		else{
				seqOrd lst1=lst, lst2=lst->next;
				while (lst2!=NULL && ele>lst2->value){
						lst1=lst2;
						lst2=lst2->next;
				}
				while (lst2!=NULL && ele==lst2->value)
						lst2=lst2->next;
				lst1->next=lst2;
		}
	return lst;
}

seqOrd leggi(){
	seqOrd lst=NULL;
	// creazione della lista lst
	int n;
	tipoValore e;
	printf("\nQuanti elementi da introdurre? "); scanf("%d", &n);
	int i;
	for (i=0; i<n; i++){
				printf("\nIntrodurre il %d^ elemento: ",i+1);
				scanf("%d", &e);
				lst=ins(e,lst);
	}
	return lst;
}

void visualizza(seqOrd lst){
		// visualizzazione della lista lst
		printf("\n\n");
		while (lst!=NULL){
				printf(" %d ", lst->value);
				lst = lst->next;
		}
		printf(" NULL");
}


