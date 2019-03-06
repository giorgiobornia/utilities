#include <stdio.h>
#include <math.h>

/*
 * Il programma calcola la somma e il massimo
 * di un insieme di numeri interi 
 * forniti nel file "series.dat".
 */


int main() {
	
	int i,n,max,sum,temp;
	FILE *fin;
	
	fin = fopen("series.dat","r+");
	if(fin == NULL)  {
		fprintf(stderr,"impossibile aprire il file series.dat!\n");
		return 1;
	}
	
	
	max = 0;
	sum = 0;
	fscanf(fin,"%d",&n); /*leggo il primo, che mi da' il numero di valori*/
	for(i = 0; i < n; i++) {
		fscanf(fin,"%d",&temp);  /*leggo il successivo*/
		if (temp > max) max = temp;  /*memorizzo il max attuale*/
		sum += temp;
	}
	
	fprintf(fin,"\n\n max = %d\n sum = %d\n",max,sum);
	
	fclose(fin);
	
	return 0;
}


/* COMMENTI
 * - E' buono perche' fa tutto "al volo", 
 *   leggendo da file e senza allocare array.
 * - Attenzione alle inizializzazioni di max e sum.
 * - Ciclo FOR se conosco a priori il numero di valori, WHILE altrimenti.
 * - Modalità "r+" per il file: leggo ma posso anche scrivere.
 */