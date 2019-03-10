#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
il file memorizza i dati della matrice
in questo modo molto generico:

- supponiamo che la matrice sia una n*m (n righe, m colonne)
- i primi due elementi del file sono n ed m
- gli altri elementi del file sono tutti i componenti della matrice
  ordinati per righe crescenti, e per ogni riga ordinati per
  colonne crescenti.
  ovvero [prima riga] [seconda riga] ... [ultima riga]
- devono esserci quindi 2+(n*m) numeri nel file
- i primi due numeri devono essere interi
- gli altri n*m numeri devono essere rappresentati in base 10, e
  - sia in forma virgola mobile +-xx.yy
  - sia in forma esponenziale +-xx.yy+-eEzzz
- tra un numero e l'altro possono esserci caratteri di tipo
  blanck, caratteri di controllo, end_of_line, cioè
  - una stessa riga della matrice può essere spezzata
  in più righe del file di testo, e
  - una riga del file di testo può contenere porzioni di
  riga di matrice, o più righe della matrice
  */


/* la matrice, dovendo essere allocata dinamicamente per
   dimensionarla esattamente alle dimensioni n*m,
   puo' essere definita:
   - o come un vettore lungo n*m (col problema di accedere
   ai dati con due indici),
   - o come un vettore di vettori (a cui poi accedere con
   il doppio indice classico).
   Qui useremo la seconda modalità, vettore di vettori.
   */

#define POS(R,C,NCOL)  ((int)(R*NCOL+C))

int load_mat(const char *nomefile, double* **pmat, int *pnrig, int *pncol)
{
#define MAXLEN 1023
#define ELIMINA_SPAZI 1
#define PRENDI_NUMERI 2

	int num=0, errore=0;
	char str[MAXLEN+1];
	char *ptr;
	char ch;
	int len=0;
	size_t size;
	int stato = ELIMINA_SPAZI;
	int r,c;

	FILE *f;
	f=fopen(nomefile,"rt");
	if(!f){
		printf("impossibile aprire file %s: errore=%d errmsg=%s\n",
			   nomefile, errno, sys_errlist[errno] );
		clearerr(f);
		return(0);
	}
	errore=0;
	ptr = str;
	*ptr = '\0';
	while ( (len<=MAXLEN) ) {
		size = fread( ptr, (size_t)1, (size_t)1 , f );
		if(size!=1) {
			if( ferror(f) ) {
				printf("impossibile leggere file %s errore=%d errmsg=%s\n",
				nomefile, errno, sys_errlist[errno] );
				clearerr(f);
				return(0);
			}
			else
				break;
		}
		ch = *ptr;
		switch(stato){
			case ELIMINA_SPAZI:
			if( (ch=='.') || (ch=='+') || (ch=='-') ||
				( (ch>='0')&&(ch<='9') )  ) {
				ptr++;
				*ptr = '\0';
				len=1;
				stato = PRENDI_NUMERI;
			}
			else
				if ( ch<=((char)32) ) {
				/* spazio da eliminare */
				}
				else {
					printf("carattere non ammesso nel file %s in posiz num=%d\n",
					nomefile, num );
					return(0);
				}
			break;

			case PRENDI_NUMERI:
			if( (ch=='.') || (ch=='+') || (ch=='-') ||
				( (ch>='0')&&(ch<='9') )  || (ch=='e') || (ch=='E')  ) {
				ptr++;
				*ptr = '\0';
				len++;
			}
			else
				if ( ch<=((char)32) ) {
					double g;
					/* spazio da eliminare */
					*ptr = '\0'; /* termino la stringa */
					ptr = str;
					len=0;
					stato = ELIMINA_SPAZI;
					/* converto la stringa in un double */
					if( sscanf( str, "%lf" , &g ) != 1 ) {
						printf("impossibile convertire la stringa %s in double \n", str );
						return(0);
					}
					/* printf("letto: %lf\n", g); */

					/* se va tutto bene */
					if (num==0) {  /* aspettavo il numero di righe */
						*pnrig = (int)g;
						if (*pnrig<=0) {
							printf("numero righe <= 0 non ammesso\n");
							return(0);
						}

					}
					else
						if (num==1) {  /* aspettavo il numero di colonne */
							*pncol = (int)g;
							if (*pncol<=0) {
								printf("numero colonne <= 0 non ammesso\n");
								return(0);
							}
							/* ora so quante sono le righe e le colonne */
							/* alloco spazio per la matrice di double */

							/* unico vettore 
							*pmat = calloc( (size_t)(*pnrig) * (size_t)(*pncol) , (size_t)sizeof(double) );
							if(!(*pmat)) {
								printf("impossibile allocare matrice nrig=%d  ncol=%d\n",
										*pnrig, *pncol );
								return(0);
							}
							*/
							*pmat = (double**)
									calloc(
										(size_t)
												(*pnrig) ,
										(size_t)
												sizeof(double*)
										);
							if(!(*pmat)) {
								printf("impossibile allocare matrice nrig=%d  ncol=%d\n",
										*pnrig, *pncol );
								return(0);
							}
							else {
								int j;
								for(j=0; j<*pnrig; j++){
									(*pmat)[j] = (double*) calloc( (size_t)(*pncol) , (size_t)sizeof(double) );
									if(!((*pmat)[j])) {
										printf("impossibile allocare matrice nrig=%d  ncol=%d\n",
												*pnrig, *pncol );
										return(0);
									}
								}
							}
						}
						else { /* num >=2 , aspetto un elemento della matrice */
							/* riga attuale, indice parte da 0 */
							r = (num-2) / (*pncol);
							/* colonna attuale, indice parte da 0 */
							c = (num-2) % (*pncol);

							/* analoghi */
							/*
							(*pmat)[POS(r,c,*pncol)] = g;
							(*pmat)[num-2] = g;
							  */
							(*pmat)[r][c] = g;

						}
					num++;
					*ptr = '\0';
				}
				else {
					printf("carattere non ammesso nel file %s in posiz num=%d\n",
							nomefile, num );
					return(0);
				}
			break;
		}
	}
	if(len>=MAXLEN) {
		printf("sequenza di caratteri %s troppo lunga\n",str);
		return(0);
	}
	if(num<=2)
		{
		printf("letti pochi numeri (%d)\n",num);
		return(0);
	}
	if(num!=( 2 + (*pnrig) * (*pncol) ))
		{
		printf("letti num=%d elementi invece di %d (nrig=%d * ncol=%d)\n",
			   num, (*pnrig) * (*pncol) , (*pnrig) , (*pncol)  );
		return(0);
	}
	return(1);
}


void print_mat(int nrig, int ncol, double* *mat)
{
	int r,c;
	for(r=0;r<nrig;r++) {
		for(c=0;c<ncol;c++) {
			printf("%lf",mat[r][c]);
			if(c<ncol-1)
				printf("\t");
		}
		printf("\n");
	}
}
int main(int argc, char* argv[] )
{
	int nrig, ncol;
	double* *mat;
	if(argc!=2) {
		printf("serve un argomento: nomefile\n");
		return(0);
	}
	if ( ! load_mat( argv[1], &mat, &nrig, &ncol) ) {
		printf("errore nel caricamento della matrice\n");
		return(0);
	}
	print_mat(nrig,ncol,mat);
	return(1);
}




