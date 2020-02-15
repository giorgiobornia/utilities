/*
  Name: albBin5b.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di caratteri dati in forma di
					stringa in preoordine con simbolo terminale '*'
					e visualizza in vari formati.
*/
#include <stdio.h>
#include <stdlib.h>

typedef char tipoValore;

typedef  struct nodo *albBin;

struct  nodo {
	 albBin sin;
	 tipoValore value;
	 albBin des;
};


typedef char *stringa;

albBin leggePreOrd(stringa &); 


void visGraf(int, albBin);
void visInOrd(albBin);
void visPreOrd(albBin);
void visPostOrd(albBin);
void visInOrdP(albBin);
void visPreOrdP(albBin);
void visPostOrdP(albBin);


main(){
	 printf("Descrivi l'albero in preordine, inserendo '*' per albero vuoto. ");
	 printf("\n? ");
	 stringa strAlb;
	 scanf("%s",strAlb);
	 albBin p=leggePreOrd(strAlb);
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
	 getchar(); getchar();
}


albBin leggePreOrd(stringa &s){
  albBin p = NULL;
  if (*s != '*') {
	 p=(albBin) malloc(sizeof(nodo));
	 p->value=*s;
	 p->sin=leggePreOrd(++s);
	 p->des=leggePreOrd(++s);
  }
  return p;
}





void visGraf(int n, albBin p){
	 if (p!=NULL){
		visGraf(n+1,p->des);
		int i;
		for (i=0;i<n;i++)
				printf("   ");
		printf("%c",p->value);
		printf("\n");
		visGraf(n+1,p->sin);
	 }
}


void visInOrd(albBin p){
		if (p!=NULL){
			visInOrd(p->sin);
			printf("%c",p->value);
			visInOrd(p->des);
		}else
			printf("*");
}
void visPreOrd(albBin p){
		if (p!=NULL){
			printf("%c",p->value);
			visPreOrd(p->sin);
			visPreOrd(p->des);
		}else
			printf("*");
}

void visPostOrd(albBin p){
		if (p!=NULL){
			visPostOrd(p->sin);
			visPostOrd(p->des);
			printf("%c",p->value);
		}else
			printf("*");
}

void visPreOrdP(albBin p){
		if (p!=NULL){
			printf("%c",p->value);
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
				printf("%c",p->value);
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
			printf("%c",p->value);
		}
}


