/*
  Name: code1.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					 implementa una coda mediante array circolari  - Es 1
*/
#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef enum{false,true} boolean;
typedef int tipoValore;

typedef struct {
	int inizio;
	tipoValore valore[N];
	int fine;
} coda;

boolean vuota(coda);
boolean piena(coda);

coda insert(coda, tipoValore);
coda extract(coda);
tipoValore testa(coda);

coda legge();
void visualizza(coda);


main(){
	 coda p;
	 p = legge();
	 visualizza(p);
	 printf("\nprimo: %d",testa(p));
	 printf("\nrimanenti: ");
	 visualizza(extract(p));
}

boolean vuota(coda c){
	return ((c.inizio+1)%(N+1)==c.fine)? true: false;
}

boolean piena(coda c){
	return (c.inizio==c.fine)? true: false;
}

coda insert(coda c, tipoValore elem) {
	if (!piena(c)){
			c.valore[c.fine]=elem;
			c.fine=(c.fine+1)%(N+1);
	}
	return c;
}

coda extract(coda c) {
	if (!vuota(c))
			c.inizio=(c.inizio+1)%(N+1);
	return c;
}

tipoValore testa(coda c) {
		return c.valore[(c.inizio+1)%(N+1)];
}


coda legge(){
	 coda p;
	 p.inizio=0;
	 p.fine=1;
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
	 while(! vuota(p)){
		  printf("%d ",testa(p));
		  p=extract(p);
	 }
	 printf("<<");
}


