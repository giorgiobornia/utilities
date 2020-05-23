#include <stdio.h>
#include <stdlib.h>

#define US 1
#define EU 2
#define UK 3

#define AREA EU
int main() {
    
    if (AREA==US) {
        printf("The currency is Dollar\n");
    }
    else if (AREA==EU) {
        printf("The currency is Euro\n");
    }
    else if (AREA==UK) {
        printf("The currency is Pound\n");
    }
    
    
    return 0;
}
