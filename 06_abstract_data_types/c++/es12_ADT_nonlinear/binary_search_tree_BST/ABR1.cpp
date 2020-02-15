/*
  Name: ABR1.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di numeri interi,
                    prendendo il valore 0 come terminazione di un ramo, 
                    lo visualizza come grafo 
                    e poi valuta se sia un ABR.
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

typedef struct nodoL *lista;

struct  nodoL {
	 tipoValore value;
	 lista next;
};


albBin creaAlbBin(albBin,tipoValore,albBin);

albBin legge(int);
void visGraf(int, albBin);
lista inOrd(albBin); // trasforma l'albero in lista visitando in preordine
void crescente(albBin);


main(){
	 printf("Inserisci numeri interi, '0' per terminare il ramo:\n");
	 albBin p = legge(0);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 crescente(p);
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


lista inOrd(albBin p){
        lista lst=NULL;
		if (p!=NULL){
			lst=inOrd(p->sin);
			if (lst!=NULL){
			   while (lst->next!=NULL)
                  lst=lst->next;
               lst->next=(lista) malloc(sizeof(tipoValore));
               lst->next->value=p->value;
               lst->next->next=inOrd(p->des);
            }else{
               lst=(lista) malloc(sizeof(tipoValore));
               lst->value=p->value;
               lst->next=inOrd(p->des);
            }
		}
		return lst;
}

void crescente (albBin p){
        lista lst=inOrd(p);
        int cresc=1;
        if (lst!=NULL && lst->next!=NULL)
                while (cresc && lst->next->next!=NULL){
                                if (lst->value > lst->next->value)
                                          cresc=0;
                                lst=lst->next;
                }
        if (cresc)
                printf("\n crescente");
        else
                printf("\n non crescente");
}        
