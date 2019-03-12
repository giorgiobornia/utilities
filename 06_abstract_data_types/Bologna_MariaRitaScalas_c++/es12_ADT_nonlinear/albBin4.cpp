/*
  Name: albBin4.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge una espressione algebrica 	in forma prefissa,
					la trasforma in un albero binario e la riscrive in
					forma infissa e postfissa.
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


typedef char stringa[100];

stringa str;
int i=0;

albBin  leggePre();

void visGraf(int, albBin);
void visInOrd(albBin);
void visPostOrd(albBin);

main(){
	 printf("Scrivi una espressione algebrica in forma PREFISSA:  ");
	 scanf("%s",str);
	 albBin p=leggePre();
	 printf("\nUna visualizzazione come grafo:\n");
	 visGraf(0,p);
	 printf("\nIn forma INFISSA:   ");
	 visInOrd(p);
	 printf("\nIn forma POSTFISSA:    ");
	 visPostOrd(p);
}


albBin leggePre(){
  albBin p;
  if (str[i]=='+' || str[i]=='*' || str[i]=='-' || str[i]=='/'){
		p=(albBin) malloc(sizeof(nodo));
		p->value=str[i];
		i++;
		p->sin=leggePre();
		i++;
		p->des=leggePre();
  }else{
		p=(albBin) malloc(sizeof(nodo));
		p->sin =NULL;
		p->value=str[i];
		p->des=NULL;
  }
  return p;
}



void visGraf(int n, albBin p){
	 if (p!=NULL){
		int i;
		visGraf(n+1,p->sin);
		for (i=0;i<n;i++)
			printf("    ");
		printf("%c\n",p->value);
		visGraf(n+1,p->des);
	 }
}


void visInOrd(albBin p){
		if (p!=NULL){
			visInOrd(p->sin);
			printf("%c",p->value);
			visInOrd(p->des);
		}
}

void visPostOrd(albBin p){
		if (p!=NULL){
			visPostOrd(p->sin);
			visPostOrd(p->des);
			printf("%c",p->value);
		}
}

