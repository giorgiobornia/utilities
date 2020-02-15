#include <stdio.h>
#include <math.h>



int main() {

	/* dichiarazioni */
	int val[100];
	int i,n,max,sum;
	FILE *fin;
	fin = fopen("series.dat","r+");
	if(fin == NULL) {
		fprintf(stderr,"impossibile aprire il file series.dat!");
		return 1;
	}
	
	/* lettura */
	fscanf(fin,"%d",&n);
	for(i = 0; i < n; i++) {
		fscanf(fin,"%d",&val[i]);
	}
	
	/* max */
	max = val[0];
	for(i = 0; i < n; i++) {
		if( val[i] > max) max = val[i];
	}
	fprintf(fin,"\n\n max = %d\n",max);
	
	
	/* sum */
	sum = 0;
	for(i = 0; i < n; i++) {
		sum += val[i];
	}
	fprintf(fin,"\n\n sum = %d\n",sum);
	
	fclose(fin);
	return 0;
}

/*
 Questo programma fa la somma e trova il massimo ma con i VETTORI.
 Questo programma e' PEGGIORE del precedente, 
 perche' non fa le cose "al volo" ma ha bisogno di MEMORIZZARE TUTTO PRIMA,
 occupando spazio in memoria.
 La differenza con il precedente e' che li' i valori sono memorizzati SU DISCO
 e letti e usati solo una volta;
 con i vettori invece i valori vengono prima caricati SU RAM, 
 e successivamente usati.
 Chiaramente conviene tenere la RAM il piu' libera possibile. 
 D'altra parte la lettura su disco puo' portare ad un RALLENTAMENTO.
 Esigenze "spazio-temporali":
  SPAZIO di MEMORIA 
        vs
  TEMPO di ESECUZIONE
  
Quindi RISORSE di SPAZIO vs RISORSE di TEMPO.
Quando leggi da file, conviene leggere all'inizio e caricare in memoria,
in modo da non dover sempre accedere al file. 
Chiaramente, quando hai portato nella memoria, hai occupato la memoria.
  
 */
