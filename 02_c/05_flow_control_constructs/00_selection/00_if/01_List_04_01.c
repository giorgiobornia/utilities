/* Use of if-else */

// Read an integer number from terminal and check if it is less than 100. Print your conclusion to terminal.







#include <stdio.h>

int main() {
int i;

printf("Dammi un intero: ");
scanf("%d", &i);

  if(i < 100)
    printf("minore di 100\n");
  else
    printf("maggiore o uguale a 100\n");
}
