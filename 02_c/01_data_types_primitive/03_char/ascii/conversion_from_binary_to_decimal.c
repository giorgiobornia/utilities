 
#include <stdio.h>

char c;
unsigned long int n=0;

void main(){
	printf("Inserisci una stringa di '1' oppure '0': ");
	do{
		c=getchar();
		n= (c =='\n')? n : n*2 + (int) c - 48 ;
	}while ( c=='1' || c=='0');
 	printf("\nHo calcolato:  %lu",n);
}
