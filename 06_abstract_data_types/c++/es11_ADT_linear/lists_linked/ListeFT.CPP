#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	 int value;
	 struct elemento *next;
} nodo;

typedef nodo *listaInt;

listaInt impila(int ele, listaInt lst){
	listaInt lstAus=(listaInt) malloc(sizeof(nodo));
	lstAus->value=ele;
	lstAus->next=lst;
	return lstAus;
}

listaInt accoda(listaInt lst, int ele){
	listaInt lstAus=lst, lstAus1;
	lstAus1=(listaInt) malloc(sizeof(nodo));
	lstAus1->value=ele;
	lstAus1->next=NULL;
	if (lst!=NULL){
		while (lst->next!=NULL)
			lst=lst->next;
		lst->next=lstAus1;
	}else
		lstAus=lstAus1;
	return lstAus;
}


listaInt leggi(){
	listaInt lst=NULL;
	// creazione della lista lst
	int n,e,scelta;
	printf("\nQuanti elementi da introdurre: \t"); scanf("%d", &n);
	if (n>0){
		printf("\nVuoi inserire: \n1) impilando; \n2) accodando \n ? "); scanf("%d", &scelta);
		int i;
		for (i=0; i<n; i++){
				printf("\nIntrodurre il %d^ numero intero: ",i+1);
				scanf("%d", &e);
				lst=(scelta==1)? impila(e,lst): accoda(lst,e);
		}
	}
	return lst;
}

void visualizza(listaInt lst){
		// visualizzazione della lista lst
		if (lst!=NULL){
			printf("\n\ntesta= %d  |  coda= ", lst->value);
			lst = lst->next;
			while (lst!=NULL){
				printf(" %d :", lst->value);
				lst = lst->next;
			}
		}
		printf(" NULL");
}

main() {
  listaInt l=leggi();
  visualizza(l);
}
