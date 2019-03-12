/*
  Name: albBin7.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di caratteri dati in forma di
					stringa in postordine con simbolo terminale '*'
					e visualizza in preordine, in ordine.
*/
#include <stdio.h>
#include <stdlib.h>

typedef char tipoValore;

typedef  struct nodoA *albBin;

struct  nodoA {
	 albBin sin;
	 tipoValore value;
	 albBin des;
};

typedef  struct nodoP *pila;

struct  nodoP {
	 albBin value;
	 pila next;
};


typedef char *stringa;


albBin  leggePostOrd(stringa);

void visGraf(int, albBin);
void visInOrd(albBin);
void visPreOrd(albBin);
void visInOrdP(albBin);
void visPreOrdP(albBin);



main(){
	 stringa strAlb;
	 printf("Descrivi l'albero in postordine, inserendo '*' per albero vuoto.\n? ");
	 scanf("%s",strAlb);
	 albBin p=leggePostOrd(strAlb);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nUna visualizzazione del sottoalbero destro:\n");
	 visGraf(0,p->des);
	 printf("\nUna visualizzazione in ordine anticipato:\n");
	 visPreOrdP(p);
	 printf("\nUna visualizzazione in ordine:\n");
	 visInOrdP(p);
	 getchar(); getchar();
}

albBin  leggePostOrd(stringa s){
  pila pAus=NULL;
  while (*s!='\0'){
		 if (*s!='*'){
		 albBin a= (albBin) malloc(sizeof(nodoA));
		 a->value=*s;
		 a->des=pAus->value;
		 pAus=pAus->next;
		 a->sin=pAus->value;
		 pAus->value=a;
	}else{
		 pila p=(pila) malloc(sizeof(nodoP));
		 p->next=pAus;
		 p->value=NULL;
		 pAus=p;
	}
	s++;
  }
  return (pAus!=NULL)? pAus->value: NULL;
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



