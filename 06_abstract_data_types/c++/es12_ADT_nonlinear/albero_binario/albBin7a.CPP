/*
  Name: albBin7a.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di caratteri dati in forma di
					stringa (formato con parentesi o con simbolo terminale)
					e visualizza in preordine, in ordine, in postordine.
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


typedef char stringa[100];

albBin leggePreOrd(stringa); //function non ricorsiva
albBin leggePostOrd(stringa);
albBin creaAlbBin(albBin,tipoValore,albBin);

void visGraf(int, albBin);
void visInOrd(albBin);
void visPreOrd(albBin);
void visPostOrd(albBin);
void visInOrdP(albBin);
void visPreOrdP(albBin);
void visPostOrdP(albBin);

void push(albBin,pila &);
albBin pop(pila &);


main(){
	 printf("Descrivi l'albero in preordine, inserendo '*' per albero vuoto.\n? ");
	 stringa strAlb;	 
	 scanf("%s",&strAlb);
	 albBin p=leggePreOrd(strAlb);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nUna visualizzazione in ordine anticipato:\n");
	 visPreOrdP(p);
	 printf("\nUna visualizzazione in ordine:\n");
	 visInOrdP(p);
	 printf("\nUna visualizzazione in ordine ritardato:\n");
	 visPostOrdP(p);
	 getchar();getchar();
}


albBin leggePreOrd(stringa s){
  pila pAus=NULL;
  int i;
  for (i=0; s[i]!='\0'; i++);
  for (--i; i>=0; i--){
	if (s[i]!='*'){
		 albBin a= (albBin) malloc(sizeof(nodoA));
		 a->value=s[i];
		 a->sin=pop(pAus);
		 a->des=pop(pAus);
		 push(a,pAus);
     }else
		 push(NULL,pAus);
  }
  return (pAus!=NULL)? pAus->value: NULL;
}


albBin leggePostOrd(stringa s){
  pila pAus=NULL;
  int i;
  for(i=0; s[i]!='\0'; i++){
	if (s[i]!='*'){
		 albBin a= (albBin) malloc(sizeof(nodoA));
		 a->value=s[i];
		 a->des=pop(pAus);
		 a->sin=pop(pAus);
		 push(a,pAus);
	}else
		 push(NULL,pAus);
  }
  return (pAus!=NULL)? pAus->value: NULL;
}


albBin creaAlbBin(albBin aDes, tipoValore elem, albBin aSin){
	albBin p=(albBin) malloc(sizeof(nodoA));
	p->sin=aSin;
	p->value=elem;
	p->des=aDes;
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


void push(albBin a, pila &p){
		 pila pAus=(pila) malloc(sizeof(nodoP));
		 pAus->next=p;
		 pAus->value=a;
		 p = pAus;
}

albBin pop(pila &p){
    if(p!=NULL){
            albBin a=p->value;
            p=p->next;
            return a;
    }else
            return NULL; 
}


