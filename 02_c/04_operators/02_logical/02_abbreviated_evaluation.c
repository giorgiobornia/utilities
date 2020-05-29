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

 while ( (i<SIZE) && ( Vet[i] != 5) ) {   
    // Since to the left of && we have a control on the index, the expression Vet[i] != 5 
    // is evaluated only if the first expression is true.
    // This avoids accessing the array Vet in a position beyond the maximum one,
    // because you would fall out of the bounds and could cause a system exception such as segmentation fault that interrupts the program

  printf( "Vet[%d]=%d\n", i , Vet[i++] );
 }

  return 0;
}
