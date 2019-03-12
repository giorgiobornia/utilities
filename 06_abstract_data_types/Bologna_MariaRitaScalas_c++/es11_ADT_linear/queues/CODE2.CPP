/*
  Name: code2.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					 Rappresenta una coda mediante puntatori  - Es 2
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
	 tipoValore value;
	 struct elemento *next;
} nodo;

typedef nodo *coda;

coda accoda(coda, tipoValore);
coda decapita(coda);
tipoValore testa(coda);

coda legge();
void visualizza(coda);


main(){
	 coda pc;
	 pc = legge();
	 printf("\nElementi inseriti: "); visualizza(pc);
	 printf("\nPrimo: %d;", testa(pc));
	 printf("\nElementi rimanenti: "); visualizza(decapita(pc));
	 printf("\nAccodiamo uno zero: "); visualizza(accoda(pc,0));
}

coda accoda(coda c,tipoValore elem) {
	coda cAus;
	cAus=(coda) malloc(sizeof(nodo));
	cAus->value=elem;
	cAus->next=NULL;
	if (c!=NULL){
		coda cs=c;
		while (cs->next!=NULL)
				cs=cs->next;
		cs->next=cAus;
	}else
		c=cAus;
	return c;
}

coda decapita(coda c) {
	 return (c!=NULL)? c->next: NULL;
}

tipoValore testa(coda c){
	 return c->value;
}

coda legge(){
	 coda c=NULL;
	 int i, n;
	 tipoValore ele;
	 printf("Quanti elementi da inserire ? ");
	 scanf("%d",&n);
	 for (i=1; i<=n; i++){
			printf("\n%d^ elemento: ",i); scanf("%d",&ele);
			c=accoda(c,ele);
	 }
	 return c;
}

void visualizza(coda c){
	 printf("<< ");
	 while(c!=NULL){
		  printf("%d ",c->value);
		  c=c->next;
	 }
	 printf("<<");
}

