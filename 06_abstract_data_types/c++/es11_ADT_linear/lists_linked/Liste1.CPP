/*
  Name: liste1.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Liste
                Introduzione alle liste - Es 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	 int value;
	 struct elemento *next;
} nodo;

typedef nodo *listaInt;


void visualizza(listaInt lst){
	// visualizzazione della lista lst
	printf("\n\n");
	while (lst!=NULL){
			printf("[%d|_]---> ", lst->value);
			lst = lst->next;
		}
	printf(" NULL");
}



main() {
	// creazione della lista lst vuota
	listaInt lst=NULL;

	visualizza(lst);

	// inserimento in lst di un nodo  con valore 1
	lst=(listaInt) malloc(sizeof(nodo));
	lst->value=1;
	lst->next=NULL;

	visualizza(lst);

	// inserimento in lst di un nodo in fondo con valore 2
	listaInt lstAus=lst;
	lstAus->next=(listaInt) malloc(sizeof(nodo));
	lstAus=lstAus->next;
	lstAus->value=2;
	lstAus->next=NULL;


	visualizza(lst);

	// inserimento in lst di un nodo in testa con valore 3
	lstAus=(listaInt) malloc(sizeof(nodo));
	lstAus->value=3;
	lstAus->next=lst;
	lst=lstAus;

	visualizza(lst);


}

