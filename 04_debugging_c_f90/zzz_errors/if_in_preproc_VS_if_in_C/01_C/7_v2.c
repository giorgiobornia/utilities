
#include <stdio.h>

int main() {
    int us = 1;
    int eu = 2;
    int uk = 3;
    
    int area = us;
    
    if (area == us){
        printf("The currency is Dollar.\n");
    }
    else if (area == eu){
        printf("The currency is Euro.\n");
    }
    else if (area == uk){
        printf("The currency is Pound.\n");
    }
    
    /*
     Assuming that the piece of code is not syntatically wrong and will not
     stop the code from compiling, if the wrong code is in within the scope of
     an unexecuted if statement, then the program will run as normal until
     that if statement if true and the wrong code is run.
     */
    
    return 0;
}
