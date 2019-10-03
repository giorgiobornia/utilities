/*
 * gcc forward_euler.c -lm
 * if you plot the x and y in two columns, then open gnuplot and simply type:
 * plot 'file.txt',  [0:1]  exp(-x)
 * 
	 

   	y'(x) = f(x,y(x)) ,  x0 <= x <= b ,  y(x0) = y0.
   	
	The function f(x,z) is defined below, along with the true solution y(x).
	the number of the problem to be solved is specified by the input variable 'numde', 
    which is used in the functions 'f' and 'y'.
    The program will request the problem parameters, along with the values of 'h' and 'iprint'.  
    'h' is the stepsize, and 'iprint' is the number of steps between each printing of the solution.
	Use h=0 and numde=0 to stop the program. This program is in Section 9.2 (Elementary Numerical Analysis, Atkinson)
*/       

#include <stdio.h>
#include <math.h>


double f(double x, double z);
double y(double x);

int numde;

int main()
{

	double xzero, yzero, b, h, truevalue, error;
	double x1, y1, x0, y0;
	int iprint, k;

    FILE * file = fopen("out.txt","w");
                
		/*  Description */
    printf("\n\nThis program uses Euler's method to solve the initial value problem\n");
    printf("y'(x) = f(x,y(x)) ,  x0 <= x <= b ,  y(x0) = y0.\n");
        
        
	while (1)  
	{
		/*  Input problem parameters */

		printf("\n\n Number of the ODE = ? Give 0 to stop : ");
		scanf("%d", &numde);
		if (numde == 0) return(0);
        
		printf("\n Give x0, b, and y0 (press Enter after each input): ");
        
		scanf("%lf %lf %lf", &xzero, &b, &yzero);

 		while (1)  
		{
            
			printf("\n\n Give the stepsize h. Give 0 to stop (press Enter after the input): ");
			scanf("%lf", &h);
            if (h == 0)
				break;	

            printf("\n\n Give the print parameter iprint (press Enter after the input): ");
			scanf("%d", &iprint);
			

			/*  Initialize  */

			x0 = xzero;	
			y0 = yzero;
            
			printf("\n\n\n");
			printf("Equation %2d \n", numde);
			printf("xzero = %9.2e\n", xzero);
			printf("b = %9.2e \n", b);
			printf("yzero = %12.5e\n", yzero);
			printf("Stepsize = %10.3e  \n", h);
			printf("Print Parameter = %3d \n", iprint);


			/*  Begin the main loop for computing the solution of
				the differential equation  */

			while (x0 + h <= b)
			{
				for (k = 1; k <= iprint; k++)  
				{
					x1 = x0 + h;
					if (x1 > b)
						break;
					y1 = y0 + h*f(x0,y0);
					x0 = x1;
					y0 = y1;
				}

				/*  Calculate error  */
				if (x1 > b)
					break;
				truevalue = y(x1);
				error = truevalue - y1;
                
				/*  Print results to terminal */
				printf("\n x = %10.3e     y(x) = %21.10e   true  %21.10e", x1, y1, truevalue);
				printf("     Error = %12.2e", error);
                
				/*  Print results to file */
				fprintf(file, " %10.3e %21.10e \n", x1, y1);
                
			}
 		}
	}
	
	fclose(file);
    
//     return 0;
	
}
      

double f(double x, double z)
{
	/*  This defines the right side of
    	the differential equation  */

	const double one = 1.0, two = 2.0;

	double result;

	switch (numde)  
	{
	case 1: result = -z;
			break;
	case 2: result = (z + x*x - two)/(x + one);
			break;
	case 3: result = pow(cos(z), 2.0);
			break;
	}
	
	return(result);
}


double y(double x)
{
	/*  This gives the true solution of
    	the initial value problem. */

	const double one = 1.0, two = 2.0;

	double result, x1;

	switch (numde)  
	{
	case 1: result = exp(-x);
			break;
	case 2: x1 = x + one;
			result = x*x - two*(x1*log(x1) - x1);
			break;
	case 3: result = atan(x);
			break;
	}
	
	return(result);
}
