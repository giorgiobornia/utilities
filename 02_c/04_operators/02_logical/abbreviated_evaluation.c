#include <stdio.h>

// Supponiamo di avere un vettore di interi, con SIZE elementi,
// vogliamo stampare tutti gli elementi del vettore
// o fino all'ultimo
// o fino a che non incontriamo un elemento che vale 17, nel qual caso non
// vogliamo stampare 17 e vogliamo interrompere la stampa.

#define SIZE 10

int main() {
    
int Vet[SIZE];

int i = 0;

while ( (i<SIZE) && (Vet[i]!=17) ) {   //l'espressione Vet[i]!=17 viene valutata solo se è stata valutata vera la prima espressione (i<SIZE).
                                       // Ciò consente di evitare di accedere alla variabile Vet in una posizione
                                       // maggiore o uguale della posizione numero SIZE, perchè si cadrebbe fuori
                                       // dal vettore e si potrebbe causare un eccezione di sistema del tipo
                                       // segmentation fault che causa l'interruzione traumatica del programma.

  printf( "Vet[%d]=%d\n", i , Vet[i++] );
}

return 0;
}
