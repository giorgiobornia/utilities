/*
  Name: pile4.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Pile
					controlla se una data espressione algebrica
					ha parentesi inserite correttamente  - Es 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef char tipoValore;

typedef struct elemento {
    tipoValore value;
    struct elemento *next;
} nodo;

typedef nodo *pila;

pila push(tipoValore, pila);
pila pop(pila);
tipoValore top(pila);


main(){
	 pila p=NULL;
	 char espr[50];
	 int scorretta=0;
	 printf("Inserisci espressione algebrica: ");
	 scanf("%s",&espr);
	 int i;
	 for (i=0; espr[i]!='\0' && !scorretta; i++)
		if (espr[i]=='(')
			p=push('(',p);
		else
			if (espr[i]==')')
					if (p!=NULL)
						p=pop(p);
					else
						scorretta++;
	 if (p!=NULL)
		scorretta++;
	 if (scorretta)
			printf("Scorretta");
	 else
			printf("Corretta");
}

pila push(tipoValore elem, pila p) {
	 pila pAus;
	 pAus = (pila) malloc(sizeof(nodo));
	 pAus->value = elem;
	 pAus->next = p;
	 return pAus;
}

pila pop(pila p) {
	 return (p!= NULL)? p->next: NULL;
}

tipoValore top(pila p){
	 return p->value;
}


