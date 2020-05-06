#include <stdio.h>

#define US 1
#define EU 2
#define UK 3
#define AREA UK

int main()
{
    #if (AREA == US)
        printf("The currency is Dollar\n");
    #elif (AREA == EU)
        printf("The currency is Euro\n");
    #elif (AREA == UK)
        printf("The currency is Pound\n");
    #endif
    return 0;
}
