#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void bisection(FILE * outfile, const int n_max, const double eps, const double a0, const double b0) {
    
	int n;
    double a, b, c, err, err_old;
    
    a = a0;
    b = b0;
    
 	if( fun(a) * fun(b) >= 0. ) {
		fprintf(stderr, "f(a) * f(b) > 0!! No zeros in the interval\n");
		abort();
	}
	
	err = 1.e+6; 
    err_old = 1.e+6;
	n = 0;
    
	while(err > eps && n < n_max) {
        
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
        
	fprintf(outfile, "| %2d | %16.10f | %16.10e | %+e |\n", n, c, err, fun(c));
// 		printf("conv_rate = %e\n", err/err_old);
        
		err_old = err;
	}
	
	printf("The zero is %f (err = %f, iteration %d)\n", c, err, n);
    
    
    
}




int main() {
	
	double a0, b0, eps;
	
	FILE * outfile = stdout;
    
    const int n_max = 50;
    a0 = -0.5;
    b0 = 0.2;
    eps = 1.e-7;
    
    bisection(outfile, n_max, eps, a0, b0);
	
	return 0;
    
}

double fun(double x) {

	double y;
	y = sin(x - 0.1);
//     y =  x * x - x;
// 	y = exp(x) + x - 2.;  /* zero ~= 0442854 */
    
	return y;
}


