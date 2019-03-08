/*
  Name: ABR3.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari di Ricerca
		      Legge n di numeri interi, li inserisce in un ABR crescente
              e poi lo rappresenta in forma di grafo. Legge inoltre un numero
              intero e cerca se è compreso nell'albero.
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
void visGraf(int, albBin);

int trovato(tipoValore, albBin); // 0 = non trovato, 1 = trovato


main(){
	 albBin p = legge();
	 printf("\nAlbero:\n");
	 visGraf(0,p);
	 printf("\nInserisci un numero intero:\n");
	 int n;
	 scanf("%d",&n);
	 if (trovato(n,p))
	       printf("\nIl numero e' presente nell'albero:\n");
     else
	       printf("\nIl numero non e' presente nell'albero:\n");
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


int trovato(tipoValore val, albBin p){
  if (p!=NULL){
	if ( val == p->value)
       return 1; 
	if ( val < p->value)
       return trovato(val,p->sin);
  	if ( val > p->value)
       return trovato(val,p->des); 
  }else
	return 0;
}

