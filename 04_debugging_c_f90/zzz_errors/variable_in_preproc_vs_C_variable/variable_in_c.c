 #include <stdio.h>

 /* Thanks to having declared h and w as double, this program is correct */
 
 int main(){
     
    double h = 7;
    double w = 23;
    double area;
    
    printf("The height of the triangle is: %lf\n", h);
    printf("The width of the triangle is: %lf\n", w);
    
    area = (w * h) / 2;
    
    printf("The area of the triangle is: %lf\n", area);
    return 0;
}
