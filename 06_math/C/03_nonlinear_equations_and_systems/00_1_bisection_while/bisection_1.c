#include <stdio.h>
#include <math.h>

/*Programma per il calcolo dello 
 zero di una funzione
 con il metodo di bisezione.
 Si fornisce una funzione in un intervallo.
 In tale intervallo si assume che
 la funzione sia continua
 e abbia al piu' uno zero.
 */

double fun(double);

int main () {
	
	int n;
	double a, b, c, eps, err, err_old;
	
	FILE *bisfile;
	bisfile = fopen("bisez.in","r");
	fscanf(bisfile,"%lf",&a);
	fscanf(bisfile,"%lf",&b);
	fscanf(bisfile,"%lf",&eps);
	
	printf(" a= %f b = %f\n eps = %f\n",a,b,eps);
	
 	if( fun(a)*fun(b) >= 0. ) {
		fprintf(stderr,"f(a)*f(b) > 0!! No zeri nell'intervallo\n");
		return 1;
	}
	
	err = 1.e+6; err_old = 1.e+6;
	n = 0;
    
	while(err > eps) {
		c = .5*(a+b);
		n++;
        
		if( fun(a) * fun(c) < 0.) {
			b = c;
		}
		else if( fun(a) * fun(c) == 0.) {
			printf("incredibile! ho beccato lo zero esatto!! c = %f",c);
			return 0;
		}
		else {
			a = c;
		}
		
		err = fabs(fun(c)); /*controllo sulle ordinate*/
		printf("conv_rate = %e\n",err/err_old);
		err_old = err;
	}
	
	printf("lo zero vale %f (err = %f, iterazione %d)\n",c,err,n);
	
	return 0;
}

double fun(double x) {

	double y;
	y = sin(x - 0.1);
	
	return y;
}


/* COMMENTI
 * - E' necessaria a priori la conoscenza di alcune proprieta' della funzione.
 * - Dimezzamento dell'intervallo d'indagine ad ogni ciclo.
 * - Inizializzazione dell'errore per innescare il ciclo while.
 * - Controllo dell'errore sulle ascisse o sulle ordinate.
 */
