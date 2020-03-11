#include <stdio.h>

int main() {
    
  FILE * infile;
  
  double x_0;
  
  infile = fopen("data.in", "r");
  
    fscanf(infile, "%lf", & x_0);
  
    printf("My initial guess is %lf \n", x_0);
  
  fclose(infile);
    
    
}
