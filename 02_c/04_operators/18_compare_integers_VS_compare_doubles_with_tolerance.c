
#include <stdio.h>
#include <math.h>

#define R_VALUE  3.14

int main() {
    
    int i = 5;
    double r = R_VALUE;
    
    if (i == 5)  printf("Comparison of integers, no rounding needed for them\n");
    if (r == R_VALUE) printf("Comparison of doubles, right after initialization, %25.17e\n", r);
    
    printf("Now comparison of doubles, after composition of functions that give the identity function as a result\n");
    
    printf("Division and then multiplication: ");
    r = R_VALUE;
    r = (r / 10.3) * 10.3;
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    
    printf("Multiplication and then division: ");
    r = R_VALUE;
    r = (r * 10.3) / 10.3;
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    
    printf("Square and then square root: ");
    r = R_VALUE;
    r =  sqrt(pow(r, 2.));
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    
    printf("Square root and then square: ");
    r = R_VALUE;
    r =  pow(sqrt(r), 2.);
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    
    printf("Square root times square root: ");
    r = R_VALUE;
    r =  sqrt(r) * sqrt(r);
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    
    printf("Cosine and then arccosine: ");
    r = R_VALUE;
    r =  acos(cos(r));
    if (r == R_VALUE) printf("same number, %25.17e\n", r);
    else              printf("different number, %25.17e\n", r);
    

    printf("In exact arithmetic, the value would still be the same\n");
    printf("In finite arithmetic, it's not the case in general, because of roundoff errors\n");
    printf("Therefore, do not use == to compare doubles\n");
    printf("Use fabs(x_1 - x_2) < 1.e-15 \n");
    
    return 0;
}
