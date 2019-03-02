/* Determinazione del numero di caratteri di un file
con fseek() e ftell()	 				 	         */

#include <stdio.h>

main(int argc, char **argv)
{
FILE *fp;
long n;

if(argc < 2)
  printf("File non specificato\n");
else {
  fp = fopen(argv[1], "r");         /* apertura del file */

  if( fp != NULL ) {                /* il file esiste? */
    fseek(fp,0L,2);    /* puntatore alla fine del file */
    n = ftell(fp);     /* lettura posizione del puntatore */
    fclose(fp);                     /* chiusura del file */
    printf("Dimensione del file %ld\n", n);
  }
  else
    printf("Errore : il file %s non esiste\n", argv[1]);
}
}
