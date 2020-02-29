#include <stdio.h>

#define GREATER(a, b) ((a) > (b) ? (a) : (b))

int i, j;
double x, y;
char c1, c2;

int main() {
    
 i = 88;    j = 55;
 
 x = 83.54; y = 96.2;
 
 c1 ='c';  c2 = 'z';
 
printf("Greater: %d\n", GREATER(i, j));
printf("Greater: %f\n", GREATER(x, y));
printf("Greater: %c\n", GREATER(c1, c2));
}
