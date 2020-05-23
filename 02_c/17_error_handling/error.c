 
#include <stdio.h>
#include <errno.h>
#include <string.h>

void open_file() {
    
FILE * finput;

finput = fopen("input.txt", "rt");

if ( finput == NULL ) {
   perror("error in file opening: ");
}

return;
}


int main() {
    
  open_file();  
    
 return 0;   
}
