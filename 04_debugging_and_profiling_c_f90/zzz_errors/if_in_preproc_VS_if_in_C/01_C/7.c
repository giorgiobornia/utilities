#include <stdio.h>

#define US 1
#define EU 2
#define UK 3
#define AREA UK

int main()
{
    if (AREA == US)
        printf("The currency is Dollar\n");
    else if (AREA == EU)
        printf("The currency is Euro\n");
    else
        printf("The currency is Pound\n");
    return 0;
}
