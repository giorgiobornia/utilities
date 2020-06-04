/* Example of struct definition */

#include <stdio.h>

struct car {
  char *make;
  char *model;
  int is_sold;
};

int main()
{
struct car a1, a2;

a1.make = "FERRARI";
a1.model = "F40";
a1.is_sold = 200;

a2.make = "OPEL";
a2.model = "ASTRA";
a2.is_sold = 1200;

printf("make auto = %s\n", a1.make);
printf("model auto = %s\n", a1.model);
printf("vendute = %d\n", a1.is_sold);

printf("make auto = %s\n", a2.make);
printf("model auto = %s\n", a2.model);
printf("vendute = %d\n", a2.is_sold);
 
 return 0;

}
