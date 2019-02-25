#include <stdio.h>

/*
 Questo programma fa quasi la stessa cosa
 del programma grid.c, ma usa le MATRICI.
 Alla fine stampa su un file una matrice matx[]
 che contiene le coordinate x di tutti i punti della griglia.
 Analogamente si potrebbe stampare maty[].
  */


int main() {
	FILE *fp;
	float matx[100][100],maty[100][100];
	int i,j,nx,ny;
	float ax,bx,ay,by,hx,hy;
	
	fp = fopen("dat.out","w");
	
	printf("inserire ax,bx,nx:\n");
	scanf("%f",&ax);
	scanf("%f",&bx);
	scanf("%d",&nx);
	
	printf("inserire ay,by,ny:\n");
	scanf("%f",&ay);
	scanf("%f",&by);
	scanf("%d",&ny);

	hx = ((float)(bx-ax))/nx;
	hy = ((float)(by-ay))/ny;
	
	for(i = 0; i < nx; i++) {
		for(j = 0; j < ny; j++) {
			matx[i][j] = ax + i*hx;
			maty[i][j] = ay + j*hy;
		}
	}
	
	for(j = 0; j < ny; j++) {
		for(i = 0; i < nx; i++) {
			fprintf(fp,"%f ",matx[i][j]);
		}
		fprintf(fp,"\n");
	}
	
	
	fclose(fp);
	return 0;
}