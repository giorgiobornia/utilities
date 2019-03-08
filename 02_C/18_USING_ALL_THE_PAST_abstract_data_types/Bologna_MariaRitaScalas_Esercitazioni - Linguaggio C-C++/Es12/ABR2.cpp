/*
  Name: ABR2.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari di Ricerca
		      Legge n di numeri interi, li inserisce in un ABR crescente
              e poi lo rappresenta in forma di grafo, in forma lineare in
              ordine, in preordine e in postordine
*/


#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
	 struct elemento *sin;
	 tipoValore value;
	 struct elemento *des;
} nodo;

typedef	nodo *albBin;


albBin creaFoglia(tipoValore);
albBin insOrd(albBin,tipoValore);
albBin legge();
void visInOrd(albBin);
void visPreOrd(albBin);
void visPostOrd(albBin);
void visGraf(int, albBin);


main(){
	 albBin p = legge();
	 printf("\nAlbero:\n");
	 visGraf(0,p);
	 printf("\nVisita in ordine\n");
	 visInOrd(p);
	 printf("\nVisita in preordine\n");
	 visPreOrd(p);
	 printf("\nVisita in postordine\n");
	 visPostOrd(p);
}

albBin creaFoglia(tipoValore val){
		albBin p=(albBin) malloc (sizeof(nodo));
		p->value=val;
		p->sin=NULL;
		p->des=NULL;
		return p;
}

albBin insOrd(albBin p,tipoValore val){
    if (p!=NULL){
        if (val < p->value)
                p->sin=insOrd(p->sin,val);
        if (val > p->value)
                p->des=insOrd(p->des,val);
    }else{
        p=creaFoglia(val);
    }
    return p;
}

albBin legge(){
	int num,  i;
	tipoValore valore;
	albBin p=NULL;
	printf("Quanti valori da inserire? ");
	scanf("\t%d",&num);
	for (i=0;i<num;i++){
			printf("\nInserisci il %d^ valore: ",i+1);
			scanf("%d",&valore);
			p=insOrd(p,valore);
	}
	return p;
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

void visGraf(int n, albBin p){
	 if (p!=NULL){
		int i;
		visGraf(n+1,p->des);
		for (i=0;i<n;i++)
			printf("  ");
		printf("%d",p->value);
		printf("\n");
		visGraf(n+1,p->sin);
	 }
}

