#include <stdio.h>

/* This program is wrong! */

#define height 23
#define width 7

int main(){
    double area = (height * width) / 2;
    printf("The area of the triangle is: %lf\n", area);
    return 0;
}
