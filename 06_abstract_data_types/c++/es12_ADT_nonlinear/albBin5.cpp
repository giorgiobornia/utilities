 /*
  Name: albBin5.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di stringhe, prendendo il
					valore "*" come terminazione di un ramo, visualizza
					in forma di grafo, poi in forma prefissa
*/
#include <stdio.h>
#include <stdlib.h>

typedef char *stringa;
typedef stringa tipoValore;


typedef  struct nodo *albBin;

struct  nodo {
	 albBin sin;
	 tipoValore value;
	 albBin des;
};



albBin creaAlbBin(albBin,tipoValore,albBin);



albBin legge(int);
void visGraf(int,albBin);
void visPreOrdP(albBin);
void visPreOrd(albBin);


main(){
	 albBin p;
	 printf("Inserisci stringhe, '*' per terminare il ramo:\n");
	 p = legge(0);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nUna visualizzazione del sottoalbero destro:\n");
	 visGraf(0,p->des);
	 printf("\nUna visualizzazione in ordine anticipato:\n");
	 visPreOrd(p);
	 printf("\nUn'altra visualizzazione in ordine anticipato:\n");
	 visPreOrdP(p);
	 getchar();getchar();
}

albBin creaAlbBin(albBin aDes, tipoValore elem, albBin aSin){
	albBin p=(albBin) malloc(sizeof(nodo));
	p->sin=aSin;
	p->value=elem;
	p->des=aDes;
	return p;
}



albBin legge(int n){
	tipoValore elem=(tipoValore) malloc(sizeof(char));
	albBin p=NULL;
	printf("\n");
	int i;
	for (i=0;i<n;i++)
			printf("  ");
	printf("? ");
	scanf("%s",elem);
	if (elem[0]!='*')
			p=creaAlbBin(legge(n+1),elem,legge(n+1));
	free(elem);
	return p;
}

void visGraf(int n, albBin p){
	 if (p!=NULL){
		visGraf(n+1,p->des);
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%s",p->value);
		printf("\n");
		visGraf(n+1,p->sin);
	 }
}


void visPreOrd(albBin p){
		if (p!=NULL){
			printf("%s",p->value);
			visPreOrd(p->sin);
			visPreOrd(p->des);
		}else
			printf("*");
}

void visPreOrdP(albBin p){
		if (p!=NULL){
			printf("%s",p->value);
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


