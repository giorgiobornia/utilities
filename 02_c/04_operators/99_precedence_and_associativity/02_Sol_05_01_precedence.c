/*
 *
Assign the values
a = 5;
b = 35;
c = 7;

 Verify the value of the given expressions by printing to terminal.

a + b * c
a > b
(a + b) * (a < b)
(a + b) && (a < b)
(a + b) || (a > b)
((a * c) - b) || (a > b)
((a * c) != b) || (a > b)
(a > b) || (a < c) || (c == b)

*/




#include <stdio.h>

int main()
{
    
int a, b, c, ris;

a = 5;
b = 35;
c = 7;

ris = a + b * c;

printf("\n a) %d", ris);

ris = a > b;

printf("\n b) %d", ris);

ris = (a + b) * (a < b);

printf("\n c) %d", ris);

ris = (a + b) && (a < b);

printf("\n d) %d", ris);

ris = (a + b) || (a > b);

printf("\n e) %d", ris);

ris = ((a * c) - b) || (a > b);

printf("\n f) %d", ris);

ris = ((a * c) != b) || (a > b);

printf("\n g) %d", ris);

ris = (a > b) || (a < c) || (c == b);

printf("\n h) %d", ris);

printf("\n");


/* alternatively directly inside printf */
printf("\n a) %d", a + b * c);
printf("\n b) %d", a > b);
printf("\n c) %d", (a + b) * (a < b));
printf("\n d) %d", (a + b) && (a < b));
printf("\n e) %d", (a + b) || (a > b));
printf("\n f) %d", ((a * c) - b) || (a > b));
printf("\n g) %d", ((a * c) != b) || (a > b));
printf("\n h) %d", (a > b) || (a < c) || (c == b));

printf("\n");

}
