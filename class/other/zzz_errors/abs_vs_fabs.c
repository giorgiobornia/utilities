#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
 
 int main() {
  
     double a = 7.5;
     double b = 3.2;
     double err =  fabs(a - b);
     double err2 =  abs(a - b);
     printf("%e\n", err);
     printf("%e\n", err2);
     
     
     return 0;
 }
