 #include <stdlib.h>


int main() {
    
  char *chptr;
  int i = 1;

  chptr = (char *) malloc(512);
  
  for ( i = 0; i < 512; i++ ) {
    chptr[i] = '?';
  }

  free(chptr);
  
  return 0;
}
