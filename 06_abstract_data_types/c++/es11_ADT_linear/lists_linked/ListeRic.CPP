/*
  Name: listeRic.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Liste
                Funzioni squisitamente ricorsive per la gestione di liste
                [testa|Coda]
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct elemento {
	 int testa;
	 struct elemento *coda;
} nodo;

typedef nodo *listaInt;

listaInt legge();
void visualizza(listaInt);
int lungh(listaInt);
int maxLst(listaInt);

main(){
	 listaInt Lst=legge();
}


listaInt legge(){
	 listaInt p=NULL;
	 int si=0;
	 printf("\nCi sono elementi da inserire?\n1=si\n0=n0\n? "); scanf("%d",&si);
	 if (si){
	         p=(listaInt) malloc(sizeof(nodo));
	 	     printf("\nelemento: "); scanf("%d",&p->testa);
	 	     p->coda=legge();
	 }
	 return p;
}

void visualizza(listaInt p){
	 if (p!=NULL){
		  printf("[%d | ",p->testa);
		  visualizza(p->coda);
		  printf("]");
	 }
	  printf("NULL");
}

int lungh(listaInt p){
	int l=0;
	 if(p!=NULL){
		  l=lungh(p->coda)+1;
	 }
	return l;
}

int maxLst(listaInt p){
	 int maxEle=-MAXINT, maxC;
	 if(p!=NULL)
		  maxEle=p->testa;
		  maxC=maxLst(p->coda);
		  maxEle=(maxC>maxEle)? maxC: maxEle;
	return maxEle;
}
