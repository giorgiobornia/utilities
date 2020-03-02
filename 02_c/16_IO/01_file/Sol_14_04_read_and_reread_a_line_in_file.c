#include <stdio.h>
#include <stdlib.h>


int main() {
    
FILE *fp;
char nomefile[80], buffer[81];

printf("Digitare il nome del file:");
gets(nomefile);

/* Apre il file */
if((fp = fopen(nomefile, "r")) == NULL) {
  perror("Mancata apertura del file");
  exit(1) ;
}

/* Legge e visualizza una riga */
fgets(buffer, 80, fp);
printf("La linea letta e' : %s", buffer);

/* Ora ritorna all'inizio e rilegge una riga */
fseek(fp, 0L, 0);
fgets(buffer, 80, fp);
printf("La linea riletta e' : %s", buffer);
}
