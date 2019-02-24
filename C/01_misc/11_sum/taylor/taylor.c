#include <stdio.h>
#include <math.h>

#define NMAX 2

double deriv(int,double);
int fatt(int);
double fun(double);

int main() {

	int n,nfatt;
	double taylorsum,exactsum,fder,x0,x;
	FILE *datain;
	
	datain = fopen("taylor.in","r");
	if(datain == NULL) {
		fprintf(stderr,"file di input non trovato!\n"); 
		return 1;
	}
	
	fscanf(datain,"%lf",&x0);
	fscanf(datain,"%lf",&x);
	
	fclose(datain);
	
	printf("x0 = %f; x = %f;\n",x0,x);
	
	taylorsum = 0.;
	for(n = 0; n <= NMAX; n++) {
		fder = deriv(n,x0);
		nfatt = fatt(n);
		taylorsum += fder*pow(x-x0,n)/(double)nfatt;
	}
	
	exactsum = fun(x);
	
	printf("taylorsum = %f\n exactsum = %f\n err_r = %f\n",taylorsum,exactsum,(taylorsum-exactsum)/(x-x0));
	
	return 0;
}

double deriv(int n, double x0) {

	double y;
	double h = 0.01;
	
	switch(n) {
		case 0: {
			y = fun(x0);
		}
		break;
		
		case 1: {
			y = (fun(x0+h)-fun(x0-h))/(2.*h);
		}
		break;
		
		case 2: {
			y = (fun(x0+h)-2.*fun(x0)+fun(x0-h))/(h*h);
		}
		break;
	}
	
	return y;
}

int fatt(int n) {

	int nft;
	if(n == 0) {
		nft = 1;
	}
	else if(n == 1) {
		nft = 1;
	}
	else {
		nft = n*fatt(n-1);
	}
	return nft;
}

double fun(double x) {
	double y;
	
	y = sin(x);
	
	return y;
}