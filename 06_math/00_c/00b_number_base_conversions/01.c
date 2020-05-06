 
int posiz;
unsigned long int numero;
unsigned long int quoz10;
printf("Introduci un numero intero non negativo: ");
scanf("%lu",&numero);
quoz10 = numero;
printf("\nSi evidenziera' la cifra che ha peso  10^n  con n=");
scanf("%d",&posiz);
for (int i=1; i<=posiz; i++){
	 quoz10 = quoz10/10;
}
printf("\n La cifra che ha peso 10^%d del numero %lu e' %d",posiz, numero, quoz10 % 10);




- Usare il while per scrivere un programma che conta le cifre che compongono il numero, ovvero la sua lunghezza

- modificare il programma precedente in modo da visualizzare un numero nella forma c0*10^0+c1*10^1+c2*10^2+ ...

- Scrivere un programma che dato un numero intero lo riscriva rovesciato
