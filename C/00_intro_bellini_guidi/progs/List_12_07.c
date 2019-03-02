/* Soluzione ricorsiva del problema delle otto regine */

#include <stdio.h>
#define DIM 8

int riga[DIM];     /*riga[i] i-esima riga */
int dia1[2*DIM-1]; /*dia1[i] i-esima
                     diagonale secondaria */
int dia2[2*DIM-1]; /*dia2[i] i-esima
                     diagonale principale */
/* riga[i], dia1[i], dia2[i] possono assumere
   i valori 0 o 1: 0 libera, 1 sotto scacco */

int colonna[DIM];  /*colonna[j]=i regina
                    nella casella (i,j)*/

int nsol;          /*numero soluzioni*/
char invio;

void verifica(int);
void visualizzazione(void);
void v(void);

main()
{
int i;
nsol=0;
/*Inizializzazione righe e diagonali (libere)*/
for(i=0;i<DIM;riga[i++]=0);
for(i=0;i<2*DIM-1;dia1[i++]=0);
for(i=0;i<2*DIM-1;dia2[i++]=0);
verifica(0);
printf("\nNumero complessivo delle soluzioni = %d\n", nsol);
}

void verifica(int j)
{
int i;
for(i=0;i<DIM;i++) {
  if((riga[i]==0) && (dia1[i+j]==0) && (dia2[i-j+7]==0)) {
    colonna[j] =i;  /*regina nella casella (i,j)*/
    riga[i]    =1;  /*riga i-esima sotto scacco*/
    dia1[i+j]  =1;  /*diag. sec.(i+j)esima sotto scacco*/
    dia2[i-j+7]=1;  /*diag. pr.(i-j+7)esima sotto scacco*/

    if(j<DIM-1) verifica(j+1); /*sostituito j con j+1*/
    else {                     /*trovata una soluzione*/
      nsol=nsol+1;
      visualizzazione();
	scanf("%c",&invio);
    }

    /*Inizializzazione righe e diagonali (libere)*/
    riga[i]     = 0;
    dia1[i+j]   = 0;
    dia2[i-j+7] = 0;
  }
}
}

void visualizzazione(void)
{
int k;
printf("\n----- Soluzione numero %d  -----\n", nsol);
for(k=0;k<DIM;k++)
  printf("%d ", colonna[k]);
printf("\n");
}
