#include <stdio.h>

#define US 1
#define EU 2
#define UK 3

#define AREA US

#if AREA == 1
    #pragma message ( "The currency is Dollar" )
#elif AREA == 2
    #pragma message ( "The currency is Euro" )
#else
    #pragma message ( "The currency is Pound" )
    dolla dolla bills yall
    shoot, this dont even activate
#endif

int main(void){
    return 0;
}
