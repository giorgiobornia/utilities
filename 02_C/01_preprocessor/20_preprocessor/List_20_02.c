#include <stdio.h>

#define EU 1
#define UK 2
#define US 3

#define AREA EU

main()
{
#if AREA==US
   char moneta[]="dollaro";
#elif AREA==EU
   char moneta[]="euro";
#else
   char moneta[]="sterlina";
#endif
printf("Moneta corrente: %s\n", moneta);
}
