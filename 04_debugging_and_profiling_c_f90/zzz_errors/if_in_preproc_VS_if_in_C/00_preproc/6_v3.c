#include <stdio.h>
#include <stdlib.h>
/*
    Prompt:
    
    Write a C program that defines three preprocessor vars "US" "EU" and :UK" with values 1, 2, and 3.
    
    Define a preprocessor var AREA with one of these vars
    
    Using #if #elif #endif preprocessor constructs, print to terminal "The currency is Dollar" "The currency is Euro" or "The currency is Pound" by comparing the value of AREA with the values of US, EU, UK respectively.
*/
#define US 1
#define EU 2
#define UK 3

#define AREA US

#if AREA==US
    int main() { printf("The currency is Dollar\n"); return 0; }
#elif AREA==EU
    int main() { printf("The currency is Euro\n"); return 0;}
#elif AREA==UK
    int main() { printf("The currency is Pound\n"); return 0; }
#endif
