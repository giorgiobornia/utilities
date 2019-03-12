/*
  Name: liste3.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Liste
                Function per la lettura di n interi con inserimento in fondo 
               - Es 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	 int value;
	 struct elemento *next;
} nodo;

typedef nodo *listaInt;

listaInt leggi(int);
void visualizza(listaInt);

main() {
	// creazione della lista lst
	int n;
	printf("\nQuanti elementi da introdurre? \t"); scanf("%d", &n);
	visualizza(leggi(n));
}

listaInt leggi(int n){
	listaInt lst=NULL;
	if (n>0){
		lst=(listaInt) malloc(sizeof(nodo));
		printf("\nIntrodurre il 1^ numero intero: ");
		scanf("%d", &lst->value);
		listaInt lstAus=lst;
		int i;
		for (i=1; i<n; i++){
			lstAus->next = (listaInt) malloc(sizeof(nodo));
			lstAus=lstAus->next;
			printf("\nIntrodurre il %d^ numero intero: ",i+1);
			scanf("%d", &lstAus->value);
		}
		lstAus->next=NULL;
	}
	return lst;
}

void visualizza(listaInt lst){
	// visualizzazione della lista lst
	printf("\n\n");
	while (lst!=NULL){
			printf("[%d|_]---> ", lst->value);
			lst = lst->next;
		}
	printf(" NULL");
}

