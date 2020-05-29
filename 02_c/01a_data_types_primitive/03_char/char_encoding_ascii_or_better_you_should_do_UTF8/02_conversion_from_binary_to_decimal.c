 
#include <stdio.h>


int main() {
    
char c;
unsigned long int n=0;

printf("Insert a string of 1's or 0's: ");
	do{
		c = getchar();
		n = (c =='\n')? n : n * 2 + (int) c - 48 ; /* 48 is the encoding for 0 */
	} while ( c == '1' || c == '0');
 	printf("\n I computed:  %lu\n",n);
    
    return 0;
}
