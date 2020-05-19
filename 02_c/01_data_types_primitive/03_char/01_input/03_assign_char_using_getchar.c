#include <stdio.h>

int main() {
    
char x, y, z;

printf("Type three characters:");

x = getchar();
y = getchar();
z = getchar();

printf("You typed: ");

putchar(x);
putchar(y);
putchar(z);
putchar('\n');

}
