#include <stdio.h>
#include <stdlib.h>

/*
 * This program shows that you must be precise on how to use scanf!
 * If you declare a float, you must read it with %f
 * If you declare a double, you must read it with %lf
 * Otherwise, it doesn't work
 *
 * On the other hand, printf uses "%f" both for float and for double
 */

#define  REAL_FORMAT  double
#define  REAL_FORMAT_STRING  "double"


int main() {
 
    REAL_FORMAT a;
    char  outstr[3];
    int flag;
    double vard = 13.3;
    float varf = 13.3;

    printf("The variable I declared is of type %s\n", REAL_FORMAT_STRING);

 // You cannot specify a type at runtime, but you can specify how to CONVERT that type at runtime in scanf   
//------------- 
    outstr[0] = '%';
    printf("Do you want to read a float or a double? 0 for float, 1 for double\n");
    scanf("%d", &flag);

    if ( flag == 0 )       { outstr[1] = 'f'; }
    else if  ( flag == 1 ) { outstr[1] = 'l';  outstr[2] = 'f';  }
    else { printf("Wrong input\n");  abort(); }  
//-------------


    printf("Insert a number\n");
    scanf(outstr, &a);
 
    printf("%f\n", a);

// here there is no problem in these conversions, 
// so I wonder what exactly is wrong with scanf
// Perhaps I have to see this in the debugger    
//    printf("%f\n", vard);
//    printf("%f\n", (float) vard);
//    printf("%f\n", varf);
//    printf("%f\n", (double) varf);

    
     return 0;
    
    
    
}

