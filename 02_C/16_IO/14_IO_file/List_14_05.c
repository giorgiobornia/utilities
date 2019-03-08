/* Determinazione del numero di linee contenute in un file.
   Ogni linea è definita dal carattere di newline \n        */

#include <stdio.h>

main(int argc, char **argv)
{
char buf[100];
int linee;
FILE *fp;

if( argc < 2 )
  printf("Errato numero di parametri\n");
else {
  fp = fopen(argv[1], "r");             /* apre il file */
  if(fp!= NULL) {                       /* il file esiste? */
    linee = 0;        /* inizializza contatore di linea */
    for(;;) {               /* ciclo di lettura da file */
      if( fgets(buf,100,fp) == NULL )
        break;	                        /* fine file */
      linee++;            /* incrementa contatore linee */
    }
    fclose(fp);                         /* chiude il file */
    printf("Il file contiene %d linee\n", linee);
  }
  else
    printf("Il file %s non esiste\n",argv[1]);
}
}
