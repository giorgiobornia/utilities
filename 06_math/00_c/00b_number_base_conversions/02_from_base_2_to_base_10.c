 
# include <stdio.h>

main(){
	unsigned long int num2;
	unsigned long  int pot2=1;
	unsigned long int num10=0;
	printf("Introduci un numero naturale binario : ");
	scanf("%lu",&num2);
	while (num2>0){
		num10 = num10 + num2%10*pot2;
		num2 = num2 / 10;
		pot2 = 2*pot2;
	}
	printf("\nIn decimale equivale a %lu",num10);
}



// modificarlo introducendo un controllo preliminare sulle cifre di num2: se ce ne sono diverse da 0 o 1 non eseguire il resto del programma


// aggiungere l'output di num10 in ottale e esadecimale
