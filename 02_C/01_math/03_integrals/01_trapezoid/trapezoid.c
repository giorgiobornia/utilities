/*
	Title: Example of trapezoidal numerical integration method
*/

#include <stdio.h>
#include <math.h>
      
const double zero = 0.0, two = 2.0;

double f(double);
int numf;

main()
{
	FILE *fp;
	double a, b, x, trueint, sum, sumend, h;
	double trap, paster, error, ratio;
	int j, k, n;

	if ((fp = fopen("trapezoidal.output", "w")) == NULL)  
	{
		printf("\n\n Cannot open file trapezoidal.output\n");
		return(1);
	}

	while (1)  
	{
		printf("\n\n Give number of integrand : ");
		scanf("%d", &numf);
		if (numf == 0)  
		{
			fclose(fp);
			return(0);
		}
      
		printf("\n Give integration limits a and b : ");
		scanf("%lf %lf", &a, &b);
		printf("\n Give true answer, if known");
		printf("\n if unknown, give zero : ");
		scanf("%lf", &trueint);

		fprintf(fp, "\n\n Number of integrand = %d", numf);
		fprintf(fp, "\n Integration limits = %e %e", a, b);
		fprintf(fp, "\n True = %e", trueint);
     		 
		sumend = (f(a) + f(b))/two;
		sum = zero;
		for (j=1; j <= 9; j++)  
		{
			n = pow(2.0, (double)j);
			h = (b-a)/n;
			for (k=1; k <= n-1; k += 2)  
			{
				x = a + k*h;
				sum = sum + f(x);
			}
			trap = h*(sumend + sum);
			error = trueint - trap;
			if (j == 1) 
			{
				paster = error;
				fprintf(fp, "\n n = %3d   trap = %17.10e", n, trap);
				fprintf(fp, "   error = %9.2e", error);
			}
			else  
			{
				ratio = paster/error;
				paster = error;
				fprintf(fp, "\n n = %3d   trap = %17.10e", n, trap);
				fprintf(fp, "   Error = %9.2e   Ratio = %9.2e", error, ratio);
			}
			printf("\n n = %d  \t Error = %e", n, error);
		}
	}
}



double f(double x) 
{
	double pi = 3.14159265358979;
	double result;
      
	switch (numf)  
	{
	case 1: result = exp(-x*x);
			break;
	case 2: result = 1.0/(1.0 + x*x);
			break;
	case 3: result = 1.0/(2.0 + cos(x));
			break;
	case 4: result = exp(x)*cos(4.0*x);
			break;
	case 5: result = x*x*sqrt(x);
			break;
	case 6: result = exp(cos(x));
			break;
	case 7: result = 1.0/(1.0 + pow((x-pi), 2.0));
			break;
	case 8: result = sqrt(x);
			break;
	}

	return(result);
}

