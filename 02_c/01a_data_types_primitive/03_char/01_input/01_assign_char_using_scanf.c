#include <stdio.h>

int main() {
    
char x, y, z;

printf("Type 3 characters:");

// scanf("%c%c%c", &x, &y, &z);
scanf("%c %c %c", &x, &y, &z);  /* whitespaces in the format string are ignored */

printf("You typed: ");

printf("%c%c%c\n", x, y, z);


 return 0;
 
}
