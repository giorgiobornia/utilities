/*
  Name: alberi1.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi
		      Legge un albero di numeri interi, prendendo il
              valore 0 come terminazione di un ramo, e poi lo
              rappresenta in forma di grafo
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef  struct	nodoA *albero;
typedef  struct	nodoF *foresta;

struct nodoA{
	 tipoValore value;
	 foresta next;
};

struct nodoF{
	 albero value;
	 foresta next;
};

albero creaAlbero(tipoValore, foresta);
foresta sottoAlberi(albero);
tipoValore radAlbero(albero);

albero legge(int);
void visGraf(int, albero);


main(){
	 albero p;
	 printf("Inserisci numeri interi, '0' per terminare il ramo:\n");
	 p = legge(0);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 getchar(); getchar();
}

albero creaAlbero(tipoValore r, foresta f){
	albero p=(albero) malloc(sizeof(nodoA));
	p->value=r;
	p->next=f;
	return p;
}

foresta sottoAlberi(albero a){
 return a->next;
}

tipoValore radAlbero(albero a){
 return a->value;
}



albero legge(int n){
	tipoValore elem;
	albero p=NULL;
	printf("\n");
	int i;
	for (i=0;i<n;i++)
			printf("  ");
	printf("? ");
	scanf("%d",&elem);
	foresta f=NULL;
	if (elem!=0){
		foresta fAus=(foresta) malloc(sizeof(nodoF));
		fAus->value=legge(n+1);
		while (fAus->value!=NULL){
			fAus->next=f;
			f=fAus;
			fAus= (foresta) malloc(sizeof(nodoF));
			fAus->value=legge(n+1);
		}
		p=creaAlbero(elem,f);
	}
	return p;
}

void visGraf(int n, albero p){
	 if (p!=NULL){
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%d",p->value);
		printf("\n");
		foresta f= sottoAlberi(p);
		while (f!=NULL){
				visGraf(n+1,f->value);
				f=f->next;
		}
	 }
}

