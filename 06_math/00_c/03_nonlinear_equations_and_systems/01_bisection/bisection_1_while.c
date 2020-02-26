#include <stdio.h>
#include <math.h>

/* Compute zeros with the bisection method.
   You provide a function in an interval.
   In that interval the function is assumed to be continuous and to have at most one zero.
 */

/* COMMENTS
 * - fprintf to stderr or stdout
 * - Read inputs from file with fscanf
 * - The a priori knowledge of some function properties is required.
 * - At each cycle the interval is halved.
 * - You need to initialize the error to properly trigger the while loop.
 * - Error control either on abscissas or on ordinates.
 */


double fun(double);


int main() {
	
	int n;
	double a, b, c, eps, err, err_old;
	
	FILE * bis_file;
    
	bis_file = fopen("bisez.in", "r");
	fscanf(bis_file, "%lf", &a);
	fscanf(bis_file, "%lf", &b);
	fscanf(bis_file, "%lf", &eps);
	
	printf("a= %f, b = %f\n, eps = %f\n", a, b, eps);
	
 	if( fun(a) * fun(b) >= 0. ) {
		fprintf(stderr,"f(a) * f(b) > 0!! No zeros in the interval\n");
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
		else {
			a = c;
		}
		
		/* control on ordinate */
		err = fabs(fun(c));
//         /* control on abscissa change: with this the convergence rate is always 0.5 */
//         err = fabs(b - a);
        
		printf("conv_rate = %e\n", err/err_old);
        
		err_old = err;
	}
	
	printf("The zero is %f (err = %f, iteration %d)\n", c, err, n);
	
	return 0;
}

double fun(double x) {

	double y;
	y = sin(x - 0.1);
//     y =  x * x - x;
// 	y = exp(x) + x - 2.;  /* zero ~= 0442854 */
    
	return y;
}


