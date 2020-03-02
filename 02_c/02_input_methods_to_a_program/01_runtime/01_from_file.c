#include <stdio.h>


int main() {

  FILE * infile;
  double base, height, area;
    
  infile = fopen("data.in", "r");
    
  printf("Reading base and height from file\n");

  fscanf(infile, "%lf", &base);
  fscanf(infile, "%lf", &height);
    
  printf("Area of the rectangle \n\n");

  area = base * height;

  printf("Base: %lf\n", base);
  printf("Height: %lf\n", height);
  printf("Area: %lf\n", area);
  
  
  fclose(infile);   /* for every fopen(...) you have to do an fclose(...) so that the memory is released */
  
 } 

 /* More runtime: pass the filename to command line as well */
 
