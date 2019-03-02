/* Esempio di conversione da stringa a intero */
#include<stdio.h>
#include<stdlib.h>

main()
{
char annoNascita[10];
char annoCorrente[10];
int anni;

printf("Anno di Nascita: ");
scanf("%s", &annoNascita);
printf("Anno Corrente: ");
scanf("%s", &annoCorrente);

anni = atoi(annoCorrente)-atoi(annoNascita);

printf("Eta': %d\n", anni);
}
