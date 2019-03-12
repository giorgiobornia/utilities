/*
  Name: code4.cpp
  Copyright:
  Author: Roberto Ricci
  Date: 12/03/04 22.37
  Description: STRUTTURE LINEARI DINAMICHE: Code
					 implementa la struttura coda mediante
					 una lista circolare  - Es 4
*/
#include <stdio.h>
#include <stdlib.h>

typedef int tipoValore;

typedef struct elemento {
	 tipoValore value;
	 struct elemento *next;
} nodo;

typedef nodo *queue;

tipoValore first(queue);
tipoValore last(queue);
queue enqueue(queue, tipoValore);
queue dequeue(queue);

queue legge();
void visualizza(queue);

main(){
	 queue pc;
	 pc = legge();
	 printf("\nElementi inseriti: "); visualizza(pc);
	 printf("\nTesta: %d;", first(pc));
	 printf("\nElementi rimanenti: "); visualizza(dequeue(pc));
	 printf("\nUltimo: %d;", last(pc));
	 printf("\nAggiungiamo uno zero: "); visualizza(enqueue(pc,0));
}

tipoValore first(queue c){
	 return (c->next)->value;
}

tipoValore last(queue c){
	 return c->value;
}

queue enqueue(queue c,tipoValore elem) {
	queue pAus=(queue) malloc(sizeof(nodo));
	pAus->value=elem;
	if (c!=NULL){
		pAus->next=c->next;
		c->next=pAus;
		c=c->next;
	}else{
		pAus->next=pAus;;
		c=pAus;
	}
	return c;
}

queue dequeue(queue c) {
	if (c!=NULL)
		if (c!=c->next)
			c->next=(c->next)->next;
		else
			c=NULL;
	return c;
}


queue legge(){
	 queue c=NULL;
	 int i, n;
	 tipoValore ele;
	 printf("Quanti elementi da inserire ? ");
	 scanf("%d",&n);
	 for (i=1; i<=n; i++){
			printf("\n%d^ elemento: ",i); scanf("%d",&ele);
			c=enqueue(c,ele);
	 }
	 return c;
}

void visualizza(queue c){
	printf("<< ");
	if (c!=NULL){
		queue pc=c;
		do{
		  printf("%d ",first(pc));
		  pc=pc->next;
		}while(pc!=c);
	}
	printf("<<");
}


