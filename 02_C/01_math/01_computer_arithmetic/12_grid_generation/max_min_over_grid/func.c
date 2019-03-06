#include <stdio.h>
#include <math.h>

/*
 * 
Questo programma
usa la chiamata ad una funzione esterna,
cosi' non ho un file di dati esterno da leggere.
Esso calcola il massimo e il minimo
della funzione exp()
all'interno di un dato intervallo
suddiviso in un certo numero di sottointervalli.
Inoltre stampa le coppie (x,y) su file.
(Si potrebbe far vedere con gnuplot anche!)

Anche in questo caso si potrebbe far vedere
che per calcolare il massimo non serve memorizzare
TUTTO il vettore e poi girarci sopra.


 */


float func(float);

int main() {
	FILE *fout;
	float xcoord[1000],fun[1000];
	float a,b;
	int n,i;
	float max,min;
	
	fout = fopen("func.out","w");
	
	printf("inserire estremi dell'intervallo a,b e numero di punti n ( n max 999!!)\n");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%d",&n);
	
	for(i = 0; i <= n; i++) {
		xcoord[i] = a + i*(b-a)/((float)n);
		fun[i] = func(xcoord[i]);
		fprintf(fout,"%f -> %f\n",xcoord[i],fun[i]);
	}
	
	max = fun[0];
	min = fun[0];
	
	for(i = 1; i <= n; i++) {
		if(fun[i] > max) max = fun[i];
		if(fun[i] < min) min = fun[i];
	}
	
	printf(" max: %f\n min: %f\n",max,min);
	
	fclose(fout);
	return 0;
}


/* -----------------*/
float func(float x) {
	
	float y;
	y = exp(x);
	
	return y;
}
