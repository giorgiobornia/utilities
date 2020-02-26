#include <stdio.h>
#include <math.h>

/* Compute zeros with the bisection method.
   You provide a function in an interval.
   In that interval the function is assumed to be continuous and to have at most one zero.
 */

double fun(double);


int main() {
	
	int n;
	double a, b, c, eps, err, err_old;
	
	FILE *bis_file;
	bis_file = fopen("bisez.in", "r");
	fscanf(bis_file, "%lf", &a);
	fscanf(bis_file, "%lf", &b);
	fscanf(bis_file, "%lf", &eps);
	
	printf(" a= %f b = %f\n eps = %f\n", a, b, eps);
	
 	if( fun(a)*fun(b) >= 0. ) {
		fprintf(stderr,"f(a)*f(b) > 0!! No zeros in the interval\n");
		return 1;
	}
	
	err = 1.e+6; 
    err_old = 1.e+6;
	n = 0;
    
	while(err > eps) {
        
		c = .5 * (a + b);
		n++;
        
		if( fun(a) * fun(c) < 0.) {
			b = c;
		}
		else if( fun(a) * fun(c) == 0.) {
			printf("incredible! I found the exact zero!! c = %f", c);  /* this will most likely never happen */
			return 0;
		}
		else {
			a = c;
		}
		
		/* control on ordinates */
		err = fabs(fun(c));
        
		printf("conv_rate = %e\n", err/err_old);
        
		err_old = err;
	}
	
	printf("The zero is %f (err = %f, iteration %d)\n", c, err, n);
	
	return 0;
}

double fun(double x) {

	double y;
	y = sin(x - 0.1);
	
	return y;
}


/* COMMENTS
 * - fprintf to stderr or stdout
 * - Use of input file for input data
 * - The a priori knowledge of some function properties is required.
 * - At each cycle the interval is halved.
 * - You need to initialize the error to properly trigger the while loop.
 * - Error control either on abscissas or on ordinates.
 */
