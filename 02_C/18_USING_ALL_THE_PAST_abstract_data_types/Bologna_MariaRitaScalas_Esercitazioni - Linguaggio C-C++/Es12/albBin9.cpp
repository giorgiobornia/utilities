/*
  Name: albBin9.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge una espressione algebrica infissa,
					la trasforma in un albero binario, la visualizza
                    in forma prefissa e postfissa.
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

typedef  struct nodoP *pilaA;

struct  nodoP {
	 albBin value;
	 pilaA next;
};

typedef  struct nodoC *pilaC;

struct  nodoC {
	 char value;
	 pilaC next;
};

typedef char *stringa;

int operatore(char);
int prcd(char,char);
albBin leggeIn(stringa);

albBin creaAlbBin(albBin,tipoValore,albBin);

void visGraf(int, albBin);

void visPreOrd(albBin);
void visPostOrd(albBin);

void pushA(albBin, pilaA &);
albBin popA(pilaA &);
void pushC(char, pilaC &);
char popC(pilaC &);




main(){
  printf("scrivi un'espressione algebrica in forma INFISSA:\n");
  stringa str;
  scanf("%s",str);
  albBin p=leggeIn(str);
  printf("\n");
  visGraf(0,p);
  printf("\nPREFISSA:  ");
  visPreOrd(p);
  printf("\nPOSTFISSA: ");
  visPostOrd(p);
  getchar(); getchar();
}

int operatore(char c){
 return (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')');
}

int prcd(char c1,char c2){
 int i;
 char opOrd[7]=")-+*/(";
 i=0;
 while(c1!=opOrd[i])
	i++;
 while(i<6  && c2!=opOrd[i])
	i++;
 return i>5;
}


albBin leggeIn(stringa str){
 pilaA pA=NULL;
 pilaC pOp=NULL;
 while (*str !='\0'){
  if(!operatore(*str))
	pushA(creaAlbBin(NULL,*str,NULL),pA);
  else{
	while(pOp!=NULL && pOp->value!='(' && prcd(pOp->value,*str))
        pushA(creaAlbBin(popA(pA),popC(pOp),popA(pA)),pA);
    if(pOp!=NULL && *str==')') 
          popC(pOp);
    else
	      pushC(*str,pOp);
  }
  str++;
 }
 while(pOp!=NULL) {
  pushA(creaAlbBin(popA(pA),popC(pOp),popA(pA)),pA);
 }
 return pA->value;
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



void visPreOrd(albBin p){
		if (p!=NULL){
			printf("%c",p->value);
			visPreOrd(p->sin);
			visPreOrd(p->des);
		}
}

void visPostOrd(albBin p){
		if (p!=NULL){
			visPostOrd(p->sin);
			visPostOrd(p->des);
			printf("%c",p->value);
		}
}


void pushA(albBin a, pilaA &p){
		 pilaA pAus=(pilaA) malloc(sizeof(nodoP));
		 pAus->next=p;
		 pAus->value=a;
		 p = pAus;
}

albBin popA(pilaA &p){
    if(p!=NULL){
            albBin a=p->value;
            p=p->next;
            return a;
    }else
            return NULL; 
}

void pushC(char c, pilaC &p){
		 pilaC pAus=(pilaC) malloc(sizeof(nodoC));
		 pAus->next=p;
		 pAus->value=c;
		 p = pAus;
}

char popC(pilaC &p){
    if(p!=NULL){
            char c=p->value;
            p=p->next;
            return c;
    }else
            return ' '; 
}


