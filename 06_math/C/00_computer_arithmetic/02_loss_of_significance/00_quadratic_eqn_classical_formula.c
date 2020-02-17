#include <stdio.h>
#include <math.h>

/*******************************************
 * Program for the solution of quadratic equations
 *******************************************/

int main() {
    
	double a, b, c;
	double Delta;
	double x1, x2;
	
	printf("\n Insert the coefficients a,b,c of the quadratic equation in the form \n a*x**2 + b*x + c = 0: \n");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\n Coefficients of the equation:\n \t a=%f \t b=%f \t c=%f \n", a, b, c);
	
	if ( a != 0) {
		Delta = b * b - 4. * a * c;
		
		printf("\n Delta = %f \n", Delta);
		
		if( Delta > 0.) {
			x1 = (-b - sqrt(Delta))/(2.*a);
			x2 = (-b + sqrt(Delta))/(2.*a);
			printf("\n The equation has two distinct real roots: \n \t x1 = %g \t x2 = %g \n\n", x1, x2);
		}
		else if( Delta == 0.) {
			x1 = -b/(2.*a);
			printf("\n The equation has two coincident real roots: \n \t x1 = x2 = %f \n\n", x1); 
		}
		else {
			printf("\n The equation has two complex roots \n\n");
		}
	}
	else {
		printf("\n Error: the coefficient a of the equation is zero. \n The equation of degree one has only one root: \n \t %g \n\n", -c/b);
	}
	
	return 0;
}
