/*
  Name: seq1.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					leggere e visualizza sequenze ordinate crescenti di numeri interi - Es 1
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

seqOrd leggi();
void visualizza(seqOrd);

int main() {
  seqOrd l = leggi();
  visualizza(l);
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

seqOrd leggi(){
	seqOrd lst=NULL;
	// creazione della lista lst
	int n;
	tipoValore e;
	printf("\nQuanti elementi da introdurre: \t"); scanf("%d", &n);
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


