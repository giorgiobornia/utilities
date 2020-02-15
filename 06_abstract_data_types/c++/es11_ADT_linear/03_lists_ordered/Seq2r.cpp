/*
  Name: seq2r.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					Gestione di una sequenza ordinata crescente con function ricorsive - Es 2
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
	if (lst!=NULL && ele>lst->value){
			lst->next=ins(ele,lst->next);
		return lst;
	}else{
		seqOrd lstAus=(seqOrd) malloc(sizeof(nodo));
		lstAus->value=ele;
		lstAus->next=lst;
		return lstAus;
	}
}

seqOrd del(tipoValore ele, seqOrd lst){
	if (lst==NULL || ele<lst->value)
				return lst;
	else{
		while (lst!=NULL && ele==lst->value)
				lst=lst->next;
		if(lst!=NULL)
				lst->next=del(ele,lst->next);
		return lst;
	}
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


