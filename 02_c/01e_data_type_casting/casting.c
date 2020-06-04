#include <stdio.h>
 
int main() {
    
    int i1 = 7;
    int i2 = 3;
    double d1 = 3.5;
    
    /* ********** Casting in operations ********* */
    
    double d2 = i1 + d1;   /* implicit casting of i1 from int to double, so that  */
    
    double d3 = i1 / i2; /* int/int gives int, which remains int even if it is cast to double */
    double d4 = (double) (i1 / i2); /* does nothing */
    
    double d5 = ( (double) i1 ) / i2; /* double/int gives double */
    double d6 = i1 / ( (double) i2 ); /* int/double gives double */
    
    
    /* ******* Casting in assignment ********* */
    int i3 = 4.9;  /* implicit casting from a constant of type double to an integer (DEMOTION): TRUNCATION of the fractional part */
    printf("%d\n", i3);
    double d7 = 3; /* implicit casting from a constant of type int to a double (PROMOTION): no loss of information */
    printf("%lf\n", d7);
    
 
   return 0;
  
}
