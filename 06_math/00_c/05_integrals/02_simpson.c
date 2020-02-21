/*
     	Title: Example of Simpson's numerical integration method.
*/

#include <stdio.h>
#include <math.h>

const double zero = 0.0, two = 2.0, three = 3.0, four = 4.0;

double f(double x);

int numf;

      

main()
{
	FILE *fp;
	double a, b, trueint, sumend, sumodd, sumeven;
	double paster, ratio, h, simpson, error, x;
	int n, j, k;
	
	if ((fp = fopen("simpson.output", "w")) == NULL) 
	{
		printf("\n Unable to open file simpson.output \n");
		return(1);
	}
	while (1) 
	{
		printf("\n Give number of integrand.  give zero to stop : ");
		scanf("%d", &numf);
		if (numf == 0)	
		{
			fclose(fp);
			return(0);
		}
      		
		printf("\n Give integration limits a and b : ");
		scanf("%lf %lf", &a, &b);
		printf("\n Give true answer, if known");
		printf("\n if unknown, give zero; but the errors");
		printf("\n will then be incorrect : ");
		scanf("%lf", &trueint);

		fprintf(fp, "\n\n");
		fprintf(fp,"\n Number of integrand = %d", numf);
		fprintf(fp, "\n Integration limits = %f %f", a, b);
		fprintf(fp, "\n True = %f", trueint);
      		
		sumend = f(a) + f(b);
		sumodd = zero;
		sumeven = zero;
		for (j=1; j <= 9; j++) 
		{
			n = pow(2.0, (double) j);
			h = (b-a)/n;
			sumeven = sumeven + sumodd;
			sumodd = zero;
			for (k=1; k <= n-1; k += 2) 
			{
				x = a + k*h;
				sumodd = sumodd + f(x);
			}
			simpson = h*(sumend + four*sumodd + two*sumeven)/three;
			error = trueint - simpson;
			if (j == 1) 
			{
				paster = error;
				fprintf(fp, "\n n = %3d   simpson = %17.10e", n, simpson);
				fprintf(fp, "   error = %9.2e", error);
			}
			else  
			{
				ratio = paster/error;
				paster = error;
				fprintf(fp, "\n n = %3d   simpson = %17.10e", n, simpson);
				fprintf(fp, "   Error = %9.2e   Ratio = %9.2e", error, ratio);
			}
			printf("\n n = %3d   simpson = %17.10e   error = %9.2e", n, simpson, 
						error);
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
