/* Scrittura di una stringa in un file */

#include <stdio.h>
#include <string.h>

main()
{
  char buf[100];        /* buffer */
  FILE *fp;             /* file pointer */
  int len;

  /* Legge da tastiera il nome del fornitore */
  printf("Inserisci un fornitore : ");
  scanf("%s",buf);
  len = strlen(buf);
  fp = fopen("fornitori", "w"); /* crea il file fornitori */

  /* Memorizza il nome del fornitore nel file */
  fwrite(buf, 1, len, fp);
  fclose(fp);                  /* chiude il file */
}
