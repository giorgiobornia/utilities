/*
  Name: code3.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					 Rappresenta una coda mediante puntatori uno al primo nodo e uno all'ultimo  - Es 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
    tipoValore value;
    struct elemento *next;
} nodo;

typedef struct{
	nodo *first;
	nodo *last;
} coda;

coda insert(coda, tipoValore);
coda extract(coda);
tipoValore primo(coda);
tipoValore ultimo(coda);

coda legge();
void visualizza(coda);


int main() {
    
	 coda p;
	 p = legge();
    printf("\n\n\n");
	 visualizza(p);
	 printf("\nprimo: %d",primo(p));
	 printf("\nrimanenti: ");
	 visualizza(extract(p));
	 printf("\nultimo: %d",ultimo(p));

}

coda insert(coda c, tipoValore elem) {
	nodo *nAus;
	nAus=(nodo*) malloc(sizeof(nodo));
	nAus->value=elem;
	nAus->next=NULL;
	if (c.first==NULL){
			c.first=nAus;
			c.last=nAus;
	} else{
			(c.last)->next=nAus;
			c.last=nAus;
	}
	return c;
}

coda extract(coda p) {
	 p.first=(p.first!=NULL)? (p.first)->next: NULL;
	 return p;
}

tipoValore primo(coda p){
	 return (p.first)->value;
}
tipoValore ultimo(coda p){
	 return (p.last)->value;
}

coda legge(){
	 coda p;
	 p.first=NULL;
	 p.last=NULL;
    int i,n;
    tipoValore ele;
	 printf("\nNum. di elementi da accodare =\t"); scanf("%d",&n);
    for (i=0; i<n; i++){
		  printf("\n%d^ elemento: ",i+1); scanf("%d",&ele);
		  p=insert(p,ele);
    }    	
    return p;
}

void visualizza(coda p){
	 printf("<< ");
	 while((p.first)!=NULL){
		  printf("%d ",(p.first)->value);
		  p.first=(p.first)->next;
	 }
	 printf("<<");
}


