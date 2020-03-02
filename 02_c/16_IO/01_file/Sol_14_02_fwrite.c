#include <stdio.h>


int main() {
    
int numwrite;
FILE *fp;
char nomefile[80];

char buffer[80] = "prova d'uso di fwrite\n Questa e' la seconda riga.\n";

printf("Digitare il nome del file: ");
gets(nomefile);
fp = fopen(nomefile, "w");
numwrite = fwrite(buffer, sizeof(char), 80, fp);
printf("%d caratteri scritti sul file %s\n", numwrite, nomefile);
printf("Controllare visualizzando il file con un editor\n");
printf("del sistema operativo in uso (esempio type, vi o Notepad)\n");
}
