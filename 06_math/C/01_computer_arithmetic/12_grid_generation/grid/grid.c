#include <stdio.h>

/*
 Questo programma legge la LARGHEZZA e LUNGHEZZA
 di un rettangolo, 
 il NUMERO di SUDDIVISIONI nx e ny
 e le memorizza in due vettori che poi 
 vengono stampati coppia a coppia.
 Facciamo la modifica del (b-a) arbitrario 
 */

int main() {
	
	int nx,ny;
	int i,j;
	float lx,ly;
	float x[100],y[100];
	
	fprintf(stderr,"inserire lx,ly,nx,ny (n massimo = 100!)\n");
	scanf("%f",&lx);
	scanf("%f",&ly);
	scanf("%d",&nx);
	scanf("%d",&ny);
	
	for(i = 0; i < nx; i++) {
		x[i] = i*lx/nx;
	}
	
	for(j = 0; j < ny; j++) {
		y[j] = j*ly/ny;
	}
	
	
	for(i = 0; i < nx; i++) {
		for(j = 0; j < ny; j++) {
			printf("(%f,%f) ",x[i],y[j]);
		}
		printf("\n");
	}
	
	return 0;
}