/*
  Name: albBin4.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge una espressione algebrica 	in forma prefissa,
					la trasforma in un albero binario e la riscrive in
					forma infissa e postfissa.
*/
#include <stdio.h>
#include <stdlib.h>

typedef char tipoValore;

typedef struct	nodo *albBin;
struct nodo {
	 albBin sin;
	 tipoValore value;
	 albBin des;
};


typedef char *stringa;



albBin leggiPre(stringa &);

void visGraf(int, albBin);

void visIn(albBin);
void  visPost(albBin);

main(){
  printf("Scrivi una espressione algebrica in forma PREFISSA:  ");
  stringa riga;
  scanf("%s",riga);
  albBin p=leggiPre(riga);
  visGraf(0,p);
  printf("\nIn forma INFISSA:  ");
  visIn(p);
  printf("\nIn forma POSTFISSA:  ");
  visPost(p);
  getchar; getchar(); getchar();
}

albBin leggiPre(stringa &str){
  albBin p=NULL;
  if (*str!='\0'){
	 if (*str=='+' || *str=='*' || *str=='-' || *str=='/'){
		p=(albBin) malloc(sizeof(nodo));
		p->value=*str;
		p->sin=leggiPre(++str);
		p->des=leggiPre(++str);
	 }else{
		p=(albBin) malloc(sizeof(nodo));
		p->sin =NULL;
		p->value=*str;
		p->des=NULL;
	 }
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


void visIn(albBin p){
  if (p!=NULL){
		visIn(p->sin);
		printf("%c ",p->value);
		visIn(p->des);
	}
}

void  visPost(albBin p){
  if (p!=NULL){
		visPost(p->sin);
		visPost(p->des);
		printf("%c ",p->value);
	}
}


