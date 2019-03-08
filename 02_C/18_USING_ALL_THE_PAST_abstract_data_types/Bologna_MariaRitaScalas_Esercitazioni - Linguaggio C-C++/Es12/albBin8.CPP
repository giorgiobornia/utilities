/*
  Name: albBin8.cpp
  Copyright: 
  Author: Roberto Ricci
  Date: 12/03/04 
  Description: STRUTTURE NON LINEARI DINAMICHE: Alberi Binari
					Legge un albero di caratteri dati in forma di
					stringa nei formati con parentesi e visualizza 
                    in preordine, in ordine, in postordine.
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


typedef char *stringa;



albBin leggePreOrd(stringa &);
albBin leggeInOrd(stringa &);
albBin leggePostOrd(stringa &);


void visGraf(int, albBin);

void visInOrd(albBin);
void visPreOrd(albBin);
void visPostOrd(albBin);
void visInOrdP(albBin);
void visPreOrdP(albBin);
void visPostOrdP(albBin);



main(){
     printf("Inserimento dei valori di un albero binario in forma unidimensionale con parentesi:");
     printf("\n1. in preordine");
     printf("\n2. in ordine");
     printf("\n3. in postordine");
     printf("\n? ");
     int scelta;
     scanf("%d",&scelta);
     albBin p=NULL;
     stringa strAlb;
     switch (scelta){
     case 1:
          printf("\n\nDescrivi l'albero in preordine -es.: 1(2(4(()7)5)3(6()))-\n");
          scanf("%s",strAlb);
          p=leggePreOrd(strAlb);
     break;
     case 2:
          printf("\n\nDescrivi l'albero in preordine -es.: (((4(7))2(5))1((6)3))-\n");
          scanf("%s",strAlb);
          p=leggeInOrd(strAlb);
     break;
     case 3:
          printf("\n\nDescrivi l'albero in preordine -es.: (((()7)45)2(6())3)1-\n");
          scanf("%s",strAlb);
          p=leggePostOrd(strAlb);
     break;
     }
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
  if (*s!='\0')
     if(*s == '(' || *s == ')')
       		++s; //salta  ')' 
     else{
          p=(albBin) malloc(sizeof(nodoA));
          p->value=*s;
          ++s;
          if(*s == '('){
                      p->sin=leggePreOrd(++s);
                      p->des=leggePreOrd(++s);
                      ++s; //salta  ')'
          }else{
          		 --s; //non avendo letto né '(' né ')'
                 p->sin=NULL;
                 p->des=NULL;
          }
      }
  return p;
}


albBin leggeInOrd(stringa &s){
  albBin p = NULL;
  if (*s != '\0'){
          if (*s == '('){
                  p=(albBin) malloc(sizeof(nodoA));
		          p->sin=leggeInOrd(++s);
		          p->value=*s;
		          p->des=leggeInOrd(++s);
          }else
                  while (*s == ')')
                      s++; 
  }
  return p;
}


albBin leggePostOrd(stringa &s){
  albBin p = NULL;
  if (*s!='\0'){
          p=(albBin) malloc(sizeof(nodoA));
          if (*s == '('){
                    	p->sin=leggePostOrd(s);
                    	p->des=leggePostOrd(++s);
                    	++s; //salta la ')' corrispondente
                    	++s; 
          }else{
                    p->sin=NULL;
                    p->des=NULL;
          }          
          p->value=*s;
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


