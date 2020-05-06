 
#include <stdio.h>

int x=3;

f(int x){
	x = 1;
	printf("  %d \n",x);
	{
	int x=2;
	printf("    %d \n",x);
	}
}

main(){
	f(x);
	printf("\n %d",x);
}

// seguire la visibilità delle variabile x
// (N.B.: Non è generalmente consigliabile utilizzare per le variabili nomi ripetuti in contesti diversi; ciò per evitare sovrapposizioni indesiderate).
