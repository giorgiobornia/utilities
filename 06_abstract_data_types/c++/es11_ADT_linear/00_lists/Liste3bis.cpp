/*
  Name: liste3bis.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Liste
                Function ricorsiva per la lettura di interi con inserimento in fondo - Es 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	 int value;
	 struct elemento *next;
} nodo;

typedef nodo *listaInt;

listaInt leggi();
void visualizza(listaInt);

main() {
	visualizza(leggi());
	getchar(); getchar();
}

listaInt leggi(){
    listaInt lst=NULL;
    int si=0;
	printf("\nCi sono elementi da inserire? \n0=no\n1=si\n?");
	scanf("%d",&si);
	if (si){
			lst = (listaInt) malloc(sizeof(nodo));
			printf("\nIntrodurre un numero intero: ");
			scanf("%d", &lst->value);
			lst->next=leggi();
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

