/*
	Title: Test subroutine newton.

	This tests the subroutine 'newton' given in Section 4.2. (Elementary Numerical Analysis, Atkinson)
*/

#include <stdio.h>
#include <math.h>


void newton(float (*f)(float), float (*df)(float), float xinit, float eps, 
		int *itmax, float *root, int *ier) ;
float fcn(float x);
float dfcn(float x);


int numf;
float c;


int main()
{
	FILE *fp;
	float x0, eps, root;
	int itmax, ier;

	if ((fp = fopen("newton.out", "w")) == NULL)  
	{
		printf("\n Cannot open file newton.out\n");
		return 1;
	}

	while (1)  
	{
		/*  Input problem parameters  */

		printf("\n\n numfcn, c, x0, eps, itmax = ? : ");
		scanf("%d %f %f %f %d", &numf, &c, &x0, &eps ,&itmax);
		if (numf == 0)  
		{
			fclose(fp);
			return 0;
		}
      
		printf("\n fcn %1d     c = %14.7e", numf, c);
		printf("\n x0 = %14.7e     eps = %10.3e", x0, eps);
		printf("     itmax = %3d", itmax);

		fprintf(fp, "\n fcn %1d     c = %14.7e", numf, c);
		fprintf(fp, "\n x0 = %14.7e     eps = %10.3e", x0, eps);
		fprintf(fp, "     itmax = %3d", itmax);
      		
		newton(fcn, dfcn ,x0, eps, &itmax, &root, &ier);

		fprintf(fp, "\n Root = %14.7e     ier = %1d", root, ier);
		fprintf(fp, "     itmax = %3d\n", itmax);
	}
}


float fcn(float x)
/*
	This calculates the function 'fcn', defining the function
	whose root is to be calculated.
*/
{
	float result;

	switch (numf)	
	{
	case 1: result = pow(x, 6.0) - x - 1.0;
			break;
	case 2: result = 99.0 + x*(-199.0 + 100.0*x);
			break;
	case 3: result = exp(c*x) - x;
			break;
	case 4: result = x + exp(-c*x*x)*cos(x);
			break;
	}
	
	return(result);
}

      
float dfcn(float x)
/*
	This calculates the derivative of the function 'fcn'.
*/
{
	float result;

	switch (numf)	
	{
	case 1: result = 6.0*pow(x, 5.0) - 1.0;
			break;
	case 2: result = 200.0*x - 199.0;
			break;
	case 3: result = c*exp(c*x) - 1.0;
			break;
	case 4: result = 1.0 - exp(-c*x*x)*(2.0*c*x*cos(x) + sin(x));
			break;
	}
	
	return(result);
}


void newton(float (*f)(float), float (*df)(float), float xinit, float eps, 
		int *itmax, float *root, int *ier) 
{
/*
	This routine calculates a root of
		f(x) = 0
	using newton's method.
	
	Input parameters:
	(1) f,df are the names of function subprograms for
	computing f(x) and df(x)=f'(x). 
	(2) xinit is an initial guess of the solution.
	(3) eps is the desired error tolerance. the test for
	convergence is
		abs(x1-x0) <= eps,
	where x1 is the current newton iterate and x0
	is the preceding iterate.
	(4) itmax is an upper limit on the number of iterates
	to be computed. When the number of iterates
	reaches this number, the program is terminated.
	Warning: itmax is altered on output.
	
	Output parameters:
	(1) root contains the computed value of the solution.
	Regardless of how the routine is terminated,
	successfully or otherwise, root will contain
	the most recently computed newton iterate.
	(2) itmax is set to the number of iterates
	computed in the routine.
	(3) ier is an error indicator.
	=0 means a successful completion of newton.
	=1 means itmax iterates were computed and the
	routine was aborted.
	=2 means that the derivative df(x) became zero
	at some newton iterate, and the routine
	was aborted.
*/

	const float zero = 0.0;
	float x0, denom, x1;
	int itnum;

	/*  Initialize  */
      
	x0 = xinit;
	itnum = 1;
	
	/*  Begin main loop  */
	
	while (1)  
	{
		denom = (*df)(x0);
		if (denom == zero) 
		{
			/*  Derivative equals zero. Terminate iteration  */

			*ier = 2;
			*root = x0;
			*itmax = itnum-1;
			return;
		}

		/*  Compute newton iteration  */
      
		x1 = x0 - (*f)(x0)/denom; 
		printf("\n %e   %e   %e ", x0, (*f)(x0), denom);
		if (fabs(x1 - x0) <= eps)  
		{
			/*  Error test satisfied  */
          
			*ier = 0;
			*root = x1;
			*itmax = itnum;
			return;
		}
      
		if (itnum <= *itmax)  
		{
			/*  Initialize for another loop  */
          
			itnum = itnum + 1;
			x0 = x1;
		}
		else  
		{
			/*  itmax iterates have been computed. Terminate  */
          	
			*ier = 1;
			*root = x1;
			return;
		}
	}
}

