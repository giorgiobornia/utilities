#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
 struct car_with_pointer {
  char * make;
  int is_sold;
};
 
 struct car_with_array {
  char make[30];
  int is_sold;
};

 int main()
{
    
  struct car_with_pointer  c1, c2;
  
   c1.make = (char *) malloc( 30 * sizeof(char));
   
   strcpy(c1.make, "Ferrari");
   
   c1.is_sold = 0;
   
   c2 = c1; /* copy structure: with this the POINTER is copied, so they have the same pointer, so whenever one name is changed
   then also the other is changed in the same way!!! */
   
  free(c1.make);
  
  
  struct car_with_array  c3, c4;
  
   strcpy(c3.make, "Ferrari");
   c3.is_sold = 0;
   
   c4 = c3; /* copy structure: with this the ARRAY is copied, 
               but if one changes one array then the other is not touched. 
               This is the correct way to do it */
               
               
   printf("%s\n", c4.make);
   printf("%d\n", c4.is_sold);
   
  printf("Morale: Pay a lot of attention when you COPY POINTERS, because they will point to the same memory location, but perhaps you wanted them to point to different ones!\n");
  
  
   printf("Another morale: you can copy structures but you cannot copy arrays alone! Therefore, perhaps one should WRAP an array inside a struct, to then use the assignment operator\n");
   
   printf("The assignment operator is the only one that works with whole structures\n");
  
 return 0;

}

