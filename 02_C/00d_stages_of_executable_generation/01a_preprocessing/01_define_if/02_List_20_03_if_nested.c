#include <stdio.h>

#define EU 1
#define US 2

#define ITALY 10
#define UK     20

#define AREA   EU
#define COUNTRY  ITALY

main()
{
    
#if AREA == EU
    
  #if COUNTRY == ITALY
	 char currency[] = "euro";
  #elif COUNTRY == UK
     char currency[] = "sterlina";
  #endif
     
#else 
   char currency[] = "dollaro";
#endif
   
 printf("Moneta corrente: %s\n", currency);

}
