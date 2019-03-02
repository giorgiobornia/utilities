#include <stdio.h>

#define EU 1
#define US 2

#define ITALIA 10
#define UK     20

#define AREA   EU
#define PAESE  ITALIA

main()
{
#if AREA==EU
  #if PAESE == ITALIA
	 char moneta[]="euro";
  #elif PAESE == UK
     char moneta[]="sterlina";
  #endif
#else 
   char moneta[]="dollaro";
#endif
printf("Moneta corrente: %s\n", moneta);
}
