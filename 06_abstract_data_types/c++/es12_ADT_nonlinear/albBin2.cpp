/*
  Name: albBin2.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di numeri interi, prendendo il
					valore 0 come terminazione di un ramo e visualizza
					come grafo, in preordine, in ordine, in postordine.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef  struct nodo *albBin;

struct  nodo {
	 albBin sin;
	 tipoValore value;
	 albBin des;
};


albBin creaAlbBin(albBin,tipoValore,albBin);



albBin legge(int);
void visGraf(int, albBin);
void visInOrd(albBin);
void visPreOrd(albBin);
void visPostOrd(albBin);
void visInOrdP(albBin);
void visPreOrdP(albBin);
void visPostOrdP(albBin);


main(){
	 albBin p;
	 printf("Inserisci numeri interi, '0' per terminare il ramo:\n");
	 p = legge(0);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nUna visualizzazione del sottoalbero destro:\n");
	 visGraf(0,p->des);
	 printf("\nUna visualizzazione in ordine anticipato:\n");
	 visPreOrdP(p);
	 printf("\nUna visualizzazione in ordine:\n");
	 visInOrdP(p);
	 printf("\nUna visualizzazione in ordine ritardato:\n");
	 visPostOrdP(p);
}

albBin creaAlbBin(albBin aDes, tipoValore elem, albBin aSin){
	albBin p=(albBin) malloc(sizeof(nodo));
	p->sin=aSin;
	p->value=elem;
	p->des=aDes;
	return p;
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
	if (elem!=0)
			p=creaAlbBin(legge(n+1),elem,legge(n+1));
	return p;
}

void visGraf(int n, albBin p){
	 if (p!=NULL){
		visGraf(n+1,p->des);
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%d",p->value);
		printf("\n");
		visGraf(n+1,p->sin);
	 }
}


void visInOrd(albBin p){
		if (p!=NULL){
			visInOrd(p->sin);
			printf("%d",p->value);
			visInOrd(p->des);
		}else
			printf("*");
}
void visPreOrd(albBin p){
		if (p!=NULL){
			printf("%d",p->value);
			visPreOrd(p->sin);
			visPreOrd(p->des);
		}else
			printf("*");
}

void visPostOrd(albBin p){
		if (p!=NULL){
			visPostOrd(p->sin);
			visPostOrd(p->des);
			printf("%d",p->value);
		}else
			printf("*");
}

void visPreOrdP(albBin p){
		if (p!=NULL){
			printf("%d",p->value);
			if (p->sin!=NULL && p->des!=NULL){
				printf("(");
				visPreOrdP(p->sin);
				visPreOrdP(p->des);
				printf(")");
			}
			if (p->sin==NULL && p->des!=NULL){
				printf("(()");
				visPreOrdP(p->des);
				printf(")");
			}
			if (p->sin!=NULL && p->des==NULL){
				printf("(");
				visPreOrdP(p->sin);
				printf("())");
			}
		}
}

void visInOrdP(albBin p){
		if (p!=NULL){
				printf("(");
				visInOrdP(p->sin);
				printf("%d",p->value);
				visInOrdP(p->des);
				printf(")");
		}
}

void visPostOrdP(albBin p){
		if (p!=NULL){
			if (p->sin!=NULL && p->des!=NULL){
				printf("(");
				visPostOrdP(p->sin);
				visPostOrdP(p->des);
				printf(")");
			}
			if (p->sin==NULL && p->des!=NULL){
				printf("(()");
				visPostOrdP(p->des);
				printf(")");
			}
			if (p->sin!=NULL && p->des==NULL){
				printf("(");
				visPostOrdP(p->sin);
				printf("())");
			}
			printf("%d",p->value);
		}
}


