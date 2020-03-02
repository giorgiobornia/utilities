/* Determina il numero di caratteri di un file esistente */

#include <stdio.h>

int main() {
    
char buf[100];   /* buffer per la lettura */
FILE *fp;        /* file pointer */
long nc;         /* contatore caratteri */
int n;           /* numero caratteri letti con fread() */
int fineFile =0; /* indica la fine della lettura del file */

fp = fopen("clienti", "r");/* apertura del file clienti */

if( fp == NULL )
/* Si è verificato un errore: il file non esiste */
  printf("Errore : il file ordini non esiste\n");
else {
  nc = 0L;                  /* inizializza il contatore */
  do {                      /* ciclo di lettura */
    /* Legge 100 caratteri dal file ordini */
    n = fread(buf, 1, 100, fp);
    if(n==0)                /* controllo di fine file */
      fineFile = 1;
    nc += n;                /* incremento del contatore */
   }
   while(fineFile==0);

   fclose(fp);             /* chiusura del file clienti */
   printf("Il file clienti contiene %ld caratteri\n", nc);
}
}
