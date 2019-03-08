/*
  Name: pile2.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Pile
					 una function per invertire una pila  - Es 2
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
    tipoValore value;
    struct elemento *next;
} nodo;

typedef nodo *pila;

pila push(tipoValore, pila);
pila pop(pila);
tipoValore top(pila);

pila inv(pila);

pila legge();
void visualizza(pila);

main(){
	 pila p;
	 p = legge();
	 visualizza(p);
	 visualizza(inv(p));
}

pila push(tipoValore elem, pila p) { 
    pila pAus;
	 pAus = (pila) malloc(sizeof(nodo));
	 pAus->value = elem;
	 pAus->next = p;
	 return pAus;
}

pila pop(pila p) { 
	 return (p!=NULL)? p->next: NULL;
}

tipoValore top(pila p){
    return p->value;
}

pila legge(){
    pila p=NULL;
    int i,n;
    tipoValore ele;
	 printf("\nNum. di elementi da impilare =\t"); scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("\n%d^ elemento: ",i+1); scanf("%d",&ele);
        p=push(ele,p);
    }    	
    return p;
}

void visualizza(pila p){
    printf("\n\n\n");
	 while(p!=NULL){
		  printf("\n%d",p->value);
		  p=p->next;
	 }
	 printf("\nNULL");
}


pila inv(pila p){
	pila pi = NULL;
	while (p!=NULL){
			pi=push(top(p),pi);
			p = pop(p);
	}
	return pi;
}
