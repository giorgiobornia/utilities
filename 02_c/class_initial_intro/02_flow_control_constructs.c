#include <stdio.h>

int main() {
 
    char a;
    
    printf("Please insert one character:\n");
    scanf("%c", &a);
    printf("My character is %c\n", a);
    
    if      ( a == 'M' )  {
        printf("Go Moretti\n");
      }
    else if ( a == 'R' ) { 
        printf("Go Ramsey\n");
    }
    else {
        printf("No more players known\n");
    }
    
 }
