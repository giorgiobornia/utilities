#include <stdio.h>

/* This program is wrong! */

#define height 23
#define width 6

int main(){
    double area = (height * width) / 2;
    printf("The area of the triangle is: %lf", area);
    return 0;
}
