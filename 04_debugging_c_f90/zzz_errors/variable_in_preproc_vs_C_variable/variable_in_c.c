 #include <stdio.h>

/*Write a program that computes the area of a triangle. Define variables of type double where you assign some
height and width values, and print the result to terminal using the printf function.*/
int main(){
    double h = 6,w = 23 ,area;
    printf("The height of the triangle is: %lf\n", h);
    printf("The width of the triangle is: %lf\n", w);
    area = (w * h) / 2;
    printf("The area of the triangle is: %lf", area);
    return 0;
}
