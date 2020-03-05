#include <stdio.h>


int main() {
 
    double a;
    
    scanf("%f", &a);  /*does not work!!!! you must use %lf for a double!!! */
    scanf("%lf", &a);
    
    printf("%f", a);
    
     return 0;
    
    
    
}

