#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** arg_value) {

    double x_0;
    char ** endptr;
    
    printf("Number of arguments %d\n", argc);
    
    printf("The executable name is %s\n", arg_value[0]);
    
    x_0 = strtod(arg_value[1], endptr);
    
    printf("The initial guess read from command line is %f\n", x_0);
    
    
    return 0;
    
  
}
