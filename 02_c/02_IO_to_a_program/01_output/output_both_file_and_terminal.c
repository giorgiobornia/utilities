#include <stdio.h>


int main() {
    
    FILE * outfiles[2];
    int i;
    
    outfiles[0] = stdout;
    outfiles[1] = fopen("file.out", "w");
    
    for (i = 0; i < 2; i++ ) {
    fprintf(outfiles[i], "Hello world \n");
//     fprintf(outfiles[1], "Hello world \n");
    }
    
    fclose(outfiles[1]);
    
    
    
    
}
