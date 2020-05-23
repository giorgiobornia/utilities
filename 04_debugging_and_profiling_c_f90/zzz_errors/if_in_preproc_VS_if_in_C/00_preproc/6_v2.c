#include <stdio.h>

#define US 1
#define EU 2
#define UK 3

#define AREA EU

#if (AREA == US)
    #define PRINTSTATEMENT printf("The currency is Dollar.\n")
#elif (AREA == EU)
    #define PRINTSTATEMENT printf("The currency is Euro.\n")

#elif (AREA == UK)
    #define PRINTSTATEMENT printf("The currency is Pound.\n")

#endif


int main() {
    
    PRINTSTATEMENT;
    
    /*
     Assuming that the piece of code is not syntatically wrong and will not
     disrupt the preprocessor, if the wrong code is in within the scope of
     a block untoched by the preprocessor, then the program will run as normal
     until that block of code is accessed.
     */
    
    return 0;
}
