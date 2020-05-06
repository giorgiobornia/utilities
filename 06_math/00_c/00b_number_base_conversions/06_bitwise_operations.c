# include <stdio.h>

main(){
	unsigned int num;
	unsigned int pot2_15= 1<<15;
	printf("Introduci un numero intero positivo : ");
	scanf("%u",&num);
	printf("\n\n%u  = ",num);
	for (unsigned int pot2=1; pot2 < pot2_15; pot2=pot2<<1)
		printf("%u + ",num & pot2);
	printf("%u ",num & pot2);
}



// modificare uno dei precedenti programmi per ottenere ancora la codifica in binario di un numero decimale
