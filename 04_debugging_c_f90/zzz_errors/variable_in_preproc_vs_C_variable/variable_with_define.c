#include <stdio.h>

/* Write the same program as before, where instead you define height and width with #define preprocessor directives. */

#define height 23
#define width 6

int main(){
    double area = (height * width) / 2;
    printf("The area of the triangle is: %lf", area);
    return 0;
}
