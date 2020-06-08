#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double  f( double x )   {
   
    double y;
    y = cos(x);
    return y;  
}
  
double  f_der( double x )   {
   
    double y;
    y = -sin(x);
    return y;  
}

void newton(FILE * outfile, 
                   const int counter_max, 
                   const double eps, 
                   const double x_in,
                   double  (* myf_ptr)( double ),
                   double  (* myf_ptr_der)( double )
                  ) {
      
    fprintf(outfile, "***** Newton's method *****\n");
   
    double x_old = x_in;
      
    double x_new;
       
    double  err = eps + 10.;
      
    int  counter = 0;
    
    fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_old);
    
    while ( err > eps && counter < counter_max ) {
        
        x_new = x_old - myf_ptr(x_old)/myf_ptr_der(x_old);
        
        /* error update */
        err = fabs( x_new - x_old );
        x_old = x_new;
        counter++;

        fprintf(outfile, "Iteration %d, x = %16.10e\n", counter, x_new);
    }
 
    x_new = x_old;
    fprintf(outfile, "Conclusion: Iteration %d, x = %16.10e\n", counter, x_new);
}

int main() {
 
    int  counter_max;
    double x_old;
    const double eps = 10.e-7;
 
    FILE * outfile = stdout;
 
    //  double  (*myf_ptr)( double );  /* function pointer declaration */
    double  (*myf_ptr[2])( double );  /* array of function pointers declaration */
 
    myf_ptr[0] = &f;
    myf_ptr[1] = &f_der;

    printf("Give me the maximum number of iterations\n");
    //scanf("%d", & counter_max);
    counter_max = 400;
    
    
    printf("\n ************* First loop on varying initial values *********** \n\n");
    
    
    x_old = 1.5;
    while ( x_old > -0.2) {
        printf("\nFor x_old = %e:\n", x_old);
        newton(outfile, counter_max, eps, x_old, myf_ptr[0], myf_ptr[1]);
        x_old = x_old - .5;
    }
    
    printf("\n For x_old = 0, we divide by f'(0) = - sin(0) = 0.\n\n");
        
    
    printf("\n ************* Second loop on varying initial values *********** \n\n");
    
    x_old = 1.5;
    while ( x_old > -0.2) {
        printf("\nFor x_old = %e:\n", x_old);
        newton(outfile, counter_max, eps, x_old, myf_ptr[0], myf_ptr[1]);
        x_old = x_old - .4;
    }
    
    printf(" Two consecutive zeros of cos(x) are distanced by pi\n");
    printf("\nFor x_old = 0.7:  \nThe algorithm converges to approx. 1.5707963, which corresponds to the zero    pi/2 of cos(x) \n");
    printf("\nFor x_old = 0.3:  \nThe algorithm converges to approx. -4.7123889, which corresponds to the zero -3 pi/2 of cos(x) \n");
    printf("\nFor x_old = -0.1:\nThe algorithm converges to approx. -10.995574, which corresponds to the zero -7 pi/2 of cos(x) \n");
    
    return 0;
}
