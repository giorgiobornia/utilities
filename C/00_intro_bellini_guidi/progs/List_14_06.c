/* Determinazione del numero di caratteri numerici
   (cifre decimali) presenti in un file      	   */

#include <stdio.h>

main(int argc, char **argv)
{
FILE *fp;
int c;
int nc;

if(argc < 2)
  printf("Errato numero di parametri\n");
else {
  fp = fopen(argv[1],"r");                    /* apre il file */
  if(fp!=NULL) {                           /* il file esiste? */
    nc = 0;                       /* inizializza il contatore */
    while((c = fgetc(fp)) != EOF)         /* ciclo di lettura */
      if(c>='0' && c<='9') nc++;   /* incrementa il contatore */
    fclose(fp);                             /* chiude il file */
    printf("Numero di caratteri numerici: %d\n", nc);
  }
  else
    printf("Il file %s non esiste\n",argv[1]);
}
}
