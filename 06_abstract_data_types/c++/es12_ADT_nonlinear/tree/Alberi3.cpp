/*
  Name: alberi3.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi
					Legge un albero di numeri interi,
                    prendendo il valore 0 come terminazione di un ramo,
                    poi ne mostra una rappresentazione a grafo, 
                    poi la rappresentazione a grafo dell'albero binario corrispondente.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef  struct	nodo *albBin;

struct nodo{
	 albBin sin;
	 tipoValore value;
	 albBin des;
};

albBin legge(int);
void visGraf(int, albBin);
void visGrafBin(int, albBin);

main(){
	printf("Inserisci numeri interi, '0' per terminare il ramo:\n");
	albBin p=legge(0);
	printf("\nUna visualizzazione come grafo:\n");
	visGraf(0,p);
	printf("\nUna visualizzazione come albero binario:\n");
	visGrafBin(0,p);
}



albBin legge(int n){
	tipoValore elem;
	albBin p=NULL;
	printf("\n");
	int i;
	for (i=0;i<n;i++)
			printf("  ");
	printf("? ");
	scanf("%d",&elem);
	if (elem!=0){
		p=(albBin) malloc(sizeof(nodo));
		p->value= elem;
		p->sin=legge(n+1);
		p->des=legge(n);
	}
	return p;
}

void visGraf(int n, albBin p){
	 if (p!=NULL){
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%d",p->value);
		printf("\n");
		visGraf(n+1,p->sin);
		visGraf(n,p->des);
	 }
}



void visGrafBin(int n, albBin p){
	 if (p!=NULL){
		visGrafBin(n+1,p->des);
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%d",p->value);
		printf("\n");
		visGrafBin(n+1,p->sin);
	 }
}

