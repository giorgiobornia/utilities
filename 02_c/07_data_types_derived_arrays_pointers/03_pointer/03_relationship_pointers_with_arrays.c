#include <stdio.h>

void main(){
	int s[5];
	int *p;	
	p=s;
	for (int i=0; i<5; i++){
		*(p+i)=i;
	}
	for (int i=0; i<=5; i++){
		printf("%d ",s[i]);
	}
	printf("\n");
	for (int i=0; i<5; i++){
		s[i]=i+5;
	}
	for (int i=0; i<5; i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	for (int i=0; i<5; i++){
		*(p++) += 5;
	}
	for (int i=0; i<5; i++){
		printf("%d ",s[i]);
	}
	p=s;
	printf("\n");
	for ( ; p<&s[4]+2; p++){
		printf("%d ",*p);
	}

}


// Occore quindi fare attenzione nell'uso di vettori, puntatori e anche stringhe: C non fa nessun controllo sulle dimensioni. Col valore sbagliato di un indice, oltre la dimensione riservata nella dichiarazione, vengono sporcate aree contigue in memoria.


// Al contrario di un array o di una matrice che occupa in memoria lo spazio necessario per tutti gli elementi, un puntatore occupa solo lo spazio atto a contenere l'indirizzo del primo elemento.


// I puntatori sono necessari per scrivere moduli che abbiano per argomento array.
