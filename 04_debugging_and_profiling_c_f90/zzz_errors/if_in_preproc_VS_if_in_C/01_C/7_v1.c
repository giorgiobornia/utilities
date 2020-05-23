#include <stdio.h>

#define US 1
#define EU 2
#define UK 3

#define AREA US

int main(void){
    if (AREA == 1){
        printf( "The currency is Dollar\n" );
    }else if (AREA == 2){
        printf( "The currency is Euro\n" );
    }else{
        printf( "The currency is Pound\n" );
        //Incorrect code will not compile!
    }
    return 0;
} 
