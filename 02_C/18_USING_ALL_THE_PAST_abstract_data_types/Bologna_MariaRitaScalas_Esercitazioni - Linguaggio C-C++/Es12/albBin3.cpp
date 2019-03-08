/*
  Name: albBin3.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di numeri interi, prendendo il
					valore 0 come terminazione di un ramo e visualizza
					le foglie.
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
void visFoglie(albBin);

main(){
	 albBin p;
	 printf("Inserisci numeri interi, '0' per terminare il ramo:\n");
	 p = legge(0);
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nLe sue foglie:\n");
	 visFoglie(p);
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


void visFoglie(albBin p){
		if (p!=NULL)
			if (p->sin==NULL && p->des==NULL) 
                        printf("%d",p->value);
			else{
                        visFoglie(p->sin);
                        visFoglie(p->des);
            }
}

