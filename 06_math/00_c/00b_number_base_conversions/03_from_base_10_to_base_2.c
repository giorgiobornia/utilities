 
# include <stdio.h>

main(){
	unsigned long int num2=0;
	unsigned long int pot10=1;
	unsigned int num10;
	printf("Introduci un numero decimale : ");
	scanf("%u",&num10);
	while (num10>0){
		num2 += num10%2*pot10;
		num10 = num10 /2;
		pot10 *=10;
	}
	printf("\nIn binario equivale a %lu",num2);
}
