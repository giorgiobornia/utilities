/*
 * gcc euler.c -lm
 * if you plot the x and y in two columns, then open gnuplot and simply type:
 * plot 'file.txt'
 * 
	Title: Demonstration of Euler's method.
	 
	This solves the initial value problem
	
   	y'(x) = f(x,y(x)) ,  x0 <= x <= b ,  y(x0)=y0.
   	
	The function f(x,z) is defined below, along with the true solution y(x).
	the number of the problem to be solved is specified by the input variable 'numde', 
    which is used in the functions 'f' and 'y'.
    The program will request the problem parameters, along with the values of 'h' and 'iprint'.  
    'h' is the stepsize, and 'iprint' is the number of steps between each printing of the solution.
	Use h=0 and numde=0 to stop the program. This program is in Section 9.2.
*/       

#include <stdio.h>
#include <math.h>

const float zero = 0.0;

float f(float x, float z);
float y(float x);

int numde;

int main()
{

	float xzero, yzero, b, h, truevalue, error;
	float x1, y1, x0, y0;
	int iprint, k;

	while (1)  
	{
		/*  Input problem parameters */

		printf("\n\n numde = ? Give 0 to stop : ");
		scanf("%d", &numde);
		if (numde == 0) return(0);
        
		printf("\n Give x0, b, and y0 (press Enter after each input): ");
        
		scanf("%f %f %f", &xzero, &b, &yzero);

		while (1)  
		{
			printf("\n\n Give h and iprint (press Enter after each input): ");
			scanf("%f %d", &h, &iprint);
			if (h==0)
				break;	

			/*  Initialize  */

			x0 = xzero;	
			y0 = yzero;
			printf("\n\n Equation %2d     xzero = %9.2e", numde, xzero);
			printf("     b = %9.2e     yzero = %12.5e", b, yzero);
			printf("\n Stepsize = %10.3e     ", h);
			printf("Print Parameter = %3d\n", iprint);


			/*  Begin the main loop for computing the solution of
				the differential equation  */

			while (x0+h <= b)
			{
				for (k=1; k <= iprint; k++)  
				{
					x1 = x0 + h;
					if (x1 > b)
						break;
					y1 = y0 + h*f(x0,y0);
					x0 = x1;
					y0 = y1;
				}

				/*  Calculate error and print results  */
				if (x1 > b)
					break;
				truevalue = y(x1);
				error = truevalue - y1;
				printf("\n x = %10.3e     y(x) = %21.10e", x1, y1);
				printf("     Error = %12.2e", error);
			}
		}
	}
}
      

float f(float x, float z)
{
	/*  This defines the right side of
    	the differential equation  */

	const float one = 1.0, two = 2.0;

	float result;

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


float y(float x)
{
	/*  This gives the true solution of
    	the initial value problem. */

	const float one = 1.0, two = 2.0;

	float result, x1;

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
