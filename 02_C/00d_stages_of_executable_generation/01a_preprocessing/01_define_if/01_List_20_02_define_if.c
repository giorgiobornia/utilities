#include <stdio.h>

#define EU 1
#define UK 2
#define US 3

#define AREA EU

int main() {
    
#if AREA == US
    
   char currency[] = "dollar";
   egergergegr

#elif AREA == EU

   char currency[] = "euro";
   
#else
   
   char currency[] = "pound";

#endif

   printf("Currency: %s\n", currency);


}



/*
 * Note: #define MYVAR 8  only substitutes MYVAR where it is a SEPARATE WORD!

      For instance, it doesn't substitute in   aaaMYVAR!
 */
