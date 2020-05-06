# include <stdio.h>
# define pot2_15 1<<15

main(){

	unsigned int num1,num2;

	printf("Introduci un numero intero non negativo:  ");
	scanf("%u",&num1);
	printf(" --> ");
	for (unsigned int pot2=pot2_15; pot2>0; pot2>>1)
		printf("%u",(num1 & pot2)?1:0);

	printf("\nIntroduci un altro numero intero non negativo:  ");
	scanf("%u",&num2);
	printf(" --> ");
	for (pot2=pot2_15; pot2>0; pot2>>=1)
		printf("%d",(num2 & pot2)?1:0);
 
	printf("\n somma\n --> ");
	for (pot2=pot2_15; pot2>0; pot2>>=1)
		printf("%d",((num1 + num2) & pot2)?1:0);
}


// Modificare il programma inserendo opportunamente la riga
// num2 = ~num2+1;
// per rappresentare la differenza binaria mediante la somma del primo numero con il complemento a uno del secondo numero più uno.
