#include <stdio.h>

union person {
     int age;
     int height;
     char first_name[20];
};

int main() {
    
    

/* All members of the union start at the SAME MEMORY LOCATION.
   Therefore, is one is written, then it overwrites the other members! */

union person john;

printf("%d\n", sizeof(int));
printf("%d\n", sizeof(char));

john.age = 23; /* Overwrites both height and the first 3 characters of first_name (int is 4 bytes, char is 1 byte only) */
printf("John is %d years old\n", john.age);
printf("%s\n", john.first_name);

john.height = 163;
printf("John is %d years old\n", john.age);
printf("%s\n", john.first_name);


 return 0;
  
}
