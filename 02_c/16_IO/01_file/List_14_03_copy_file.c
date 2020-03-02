/* Copy a file */

#include <stdio.h>

int main() {
    
FILE *fpin, *fpout;    /* file pointer */
char buf[512];         /* buffer dati */
int n;

fpin = fopen("ordini","r");     /* apre ordini in lettura */
if(fpin!=NULL) {
fpout = fopen("ordini.bak", "w");     /* crea  ordini.bak */  
  if(fpout!=NULL) {   /* ordini.bak creato correttamente? */
    for(;;) {              /* copia ordini in ordini.bak */
      n = fread(buf, 1, 512, fpin);       /* legge ordini */
      if( n == 0 ) break;       /* controllo di fine file */
      fwrite(buf, 1, n, fpout);   /* scrive in ordini.bak */
    }
    fclose(fpin);      /* chiude il file ordini */
    fclose(fpout);     /* chiude il file ordini.bak */
  }
  else {
    printf("Impossibile aprire il file ordini.bak\n");
	   fclose(fpin);          /* chiude il file ordini */
  }
}
else
/* Errore di apertura */
  printf("Il file ordini non esiste\n");
  
}
